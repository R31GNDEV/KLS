/*
Kota LockScreen
*/

#include "kls.h"
#include "mru.h"

UIColor* colorFromHexString(NSString* hexString) {
    NSString *daString = [hexString stringByReplacingOccurrencesOfString:@" " withString:@""];
    if (![daString containsString:@"#"]) {
        daString = [@"#" stringByAppendingString:daString];
    }
    unsigned rgbValue = 0;
    NSScanner *scanner = [NSScanner scannerWithString:daString];
    [scanner setScanLocation:1]; // bypass '#' character
    [scanner scanHexInt:&rgbValue];

    NSRange range = [hexString rangeOfString:@":" options:NSBackwardsSearch];
    NSString* alphaString;
    if (range.location != NSNotFound) {
        alphaString = [hexString substringFromIndex:(range.location + 1)];
    } else {
        alphaString = @"1.0"; //no opacity specified - just return 1 :/
    }

    return [UIColor colorWithRed:((rgbValue & 0xFF0000) >> 16)/255.0 green:((rgbValue & 0xFF00) >> 8)/255.0 blue:(rgbValue & 0xFF)/255.0 alpha:[alphaString floatValue]];
}

NSUserDefaults *_preferences;
BOOL _enabled;
BOOL _enabledFloater;
BOOL USE_TRANS_COLORS;


%hook HBForceCepheiPrefs
+ (BOOL)forceCepheiPrefsWhichIReallyNeedToAccessAndIKnowWhatImDoingISwear {
    return YES;
}
%end

%hook CSTeachableMomentsContainerView
- (void)_layoutCallToActionLabel{
  %orig;
  id enabled = [_preferences objectForKey:@"enabled"];
    NSString *customText = [_preferences objectForKey:@"customTextUnlock"];
 if (!customText) {
  /* customText does not exist - return */
  return;
 }
  NSUInteger characterCount = [customText length];
  if ([enabled isEqual:@1] && characterCount > 0){
    NSCharacterSet *set = [NSCharacterSet whitespaceCharacterSet];
    if ([[customText stringByTrimmingCharactersInSet: set] length] == 0) {
            customText = @"";
 }
}
 SBUILegibilityLabel *label = [self callToActionLabel];
 if (label) {
  label.string = customText;
 }
}
%end

#define USE_TRANS_COLORS 1

/* This is our own custom object for a rainbow gradient view */

@implementation GradientProgressView

@synthesize animating, progress;

- (id)initWithFrame:(CGRect)frame {

    if ((self = [super initWithFrame:frame])) {
        
        // Use a horizontal gradient
        
        CAGradientLayer *layer = (id)[self layer];
        [layer setStartPoint:CGPointMake(0.0, 0.5)];
        [layer setEndPoint:CGPointMake(1.0, 0.5)];
        
        // Create the gradient colors using hues in 5 degree increments
        
        NSMutableArray *colors = [NSMutableArray array];
#if USE_TRANS_COLORS

// Define the colors in the desired sequence
NSArray *colorSequence = @[
    [UIColor colorWithRed:91.0/255.0 green:206.0/255.0 blue:250.0/255.0 alpha:1.0], /* baby blue */
    [UIColor colorWithRed:245.0/255.0 green:169.0/255.0 blue:184.0/255.0 alpha:1.0], /* baby pink */
    [UIColor whiteColor],
    [UIColor colorWithRed:245.0/255.0 green:169.0/255.0 blue:184.0/255.0 alpha:1.0] /* baby pink */
];

// Calculate the number of steps between each color
CGFloat colorSteps = 60.0 / colorSequence.count;

for (NSInteger step = 0; step < 60; step++) {
// Determine the start and end colors for the current step
NSInteger startIndex = step / colorSteps;
NSInteger endIndex = (startIndex + 1) % colorSequence.count;

// Calculate the progress within the current step
CGFloat progresss = (step % (NSInteger)colorSteps) / colorSteps;

// Interpolate between the start and end colors using the progress
UIColor *startColor = colorSequence[startIndex];
UIColor *endColor = colorSequence[endIndex];

CGFloat startRed, startGreen, startBlue, startAlpha;
CGFloat endRed, endGreen, endBlue, endAlpha;

[startColor getRed:&startRed green:&startGreen blue:&startBlue alpha:&startAlpha];
[endColor getRed:&endRed green:&endGreen blue:&endBlue alpha:&endAlpha];

CGFloat interpolatedRed = [self interpolateValueWithStart:startRed end:endRed progress:progresss];
CGFloat interpolatedGreen = [self interpolateValueWithStart:startGreen end:endGreen progress:progresss];
CGFloat interpolatedBlue = [self interpolateValueWithStart:startBlue end:endBlue progress:progresss];
CGFloat interpolatedAlpha = [self interpolateValueWithStart:startAlpha end:endAlpha progress:progresss];

UIColor *interpolatedColor = [UIColor colorWithRed:interpolatedRed green:interpolatedGreen blue:interpolatedBlue alpha:interpolatedAlpha];

[colors addObject:(id)[interpolatedColor CGColor]];
}

#else
        for (NSInteger deg = 0; deg <= 360; deg += 5) {
            
            UIColor *color;
            color = [UIColor colorWithHue:1.0 * deg / 360.0
                               saturation:1.0
                               brightness:1.0
                                    alpha:1.0];
            [colors addObject:(id)[color CGColor]];
        }
#endif
        [layer setColors:[NSArray arrayWithArray:colors]];
        
        // Create another layer to use as a mask. The width of this layer will
        // be modified to reflect the current progress value.
        
        maskLayer = [CALayer layer];
        [maskLayer setFrame:CGRectMake(0, 0, 0, frame.size.height)];
        [maskLayer setBackgroundColor:[[UIColor blackColor] CGColor]];
        [layer setMask:maskLayer];
    }
    return self;
}

+ (Class)layerClass {
    
    // Tells UIView to use CAGradientLayer as our backing layer
    
    return [CAGradientLayer class];
}

- (void)setProgress:(CGFloat)value {
    
    if (progress != value) {
        
        // progress values go from 0.0 to 1.0
        
        progress = MIN(1.0, fabs(value));
        [self setNeedsLayout];
    }
}

- (void)layoutSubviews {
    
    // Resize our mask layer based on the current progress
    
    CGRect maskRect = [maskLayer frame];
    maskRect.size.width = CGRectGetWidth([self bounds]) * progress;
    [maskLayer setFrame:maskRect];
}

- (NSArray *)shiftColors:(NSArray *)colors {
    
    // Moves the last item in the array to the front
    // shifting all the other elements.
    
    NSMutableArray *mutable = [colors mutableCopy];
    id last = [mutable lastObject];
    [mutable removeLastObject];
    [mutable insertObject:last atIndex:0];
    return [NSArray arrayWithArray:mutable];
}

- (void)performAnimation {
    
    // Update the colors on the model layer
    
    CAGradientLayer *layer = (id)[self layer];
    NSArray *fromColors = [layer colors];
    NSArray *toColors = [self shiftColors:fromColors];
    [layer setColors:toColors];
    
    // Create an animation to slowly move the hue gradient left to right.
    
    CABasicAnimation *animation;
    animation = [CABasicAnimation animationWithKeyPath:@"colors"];
    [animation setFromValue:fromColors];
    [animation setToValue:toColors];
    [animation setDuration:0.08];
    [animation setRemovedOnCompletion:YES];
    [animation setFillMode:kCAFillModeForwards];
    [animation setTimingFunction:[CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionLinear]];
    [animation setDelegate:self];
    
    // Add the animation to our layer
    
    [layer addAnimation:animation forKey:@"animateGradient"];
}

- (void)animationDidStop:(CAAnimation *)animation finished:(BOOL)flag {
    
    if ([self isAnimating]) {
        
        [self performAnimation];
    }
}

- (void)startAnimating {
    
    if (![self isAnimating]) {
        
        animating = YES;
        
        [self performAnimation];
    }
}

- (void)stopAnimating {
    
    if ([self isAnimating]) {
        
        animating = NO;
    }
}

- (CGFloat)interpolateValueWithStart:(CGFloat)startValue end:(CGFloat)endValue progress:(CGFloat)progresss {
    return startValue + (endValue - startValue) * progresss;
}

@end

unsigned int didAddSubview = 0x0;

%hook SBFLockScreenDateView
-(CALayer *)layer {
  CALayer *origLayer = %orig;
  NSString *glowColorString = [_preferences objectForKey:@"shadowColor"];
  NSString *backColorString = [_preferences objectForKey:@"backColor"];
  NSString *borderColorString = [_preferences objectForKey:@"borderColor"];
  CGFloat setCornerRadius = [_preferences floatForKey:@"cornerRadius"];
  if (!(setCornerRadius >= 0)){
    setCornerRadius = 1;
  }
  origLayer.cornerRadius = setCornerRadius;
  if (glowColorString) {
    origLayer.shadowColor = colorFromHexString(glowColorString).CGColor;
  }
  if (backColorString) {
    origLayer.backgroundColor = colorFromHexString(backColorString).CGColor;
  }
  if (borderColorString) {
    origLayer.borderColor = colorFromHexString(borderColorString).CGColor;
  }
  origLayer.borderWidth = 1;
  origLayer.shadowOpacity = 1;
  origLayer.shadowOffset = CGSizeMake(0.0f,4.0f);
  return origLayer;
}

-(void)didMoveToWindow {
 if (!self) {
  return;
 }
 if (!self.layer) {
  return;
 }
 if ([self.layer animationForKey:@"enabledFloater"]) {
  return;
 }
 /* no idea what this does, i just saw it's here and forgot what it was supposed to do but im too busy working on a bugfix to ask kota */
 CABasicAnimation* colorAnimation = [CABasicAnimation animationWithKeyPath:@"textColorNew"];
    NSString *bend1String = [_preferences objectForKey:@"flowcolor1"];
    NSString *bend2String = [_preferences objectForKey:@"flowcolor2"];
    if (bend1String){
      UIColor *fromColor = colorFromHexString(bend1String);
      colorAnimation.fromValue = (id)fromColor.CGColor;
    }
    if (bend2String){
    UIColor *toColor = colorFromHexString(bend2String);
    colorAnimation.toValue = (id)toColor.CGColor;
    }
    colorAnimation.repeatCount = INFINITY;
    colorAnimation.duration = 5;
    colorAnimation.autoreverses = YES;
    
    [self.layer addAnimation:colorAnimation forKey:@"enabledFloater"];

 if ([_preferences boolForKey:@"enabledFloater"]) {
 CABasicAnimation *floatingLabelAnimation = [CABasicAnimation animationWithKeyPath:@"position.y"];
 floatingLabelAnimation.fromValue = [NSNumber numberWithDouble:(self.frame.origin.y + 500)];
 floatingLabelAnimation.toValue = [NSNumber numberWithDouble:(self.frame.origin.y - -200)];
 floatingLabelAnimation.duration = 5;
 floatingLabelAnimation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
 floatingLabelAnimation.autoreverses = YES;
 floatingLabelAnimation.repeatCount = INFINITY;
 [self.layer addAnimation:floatingLabelAnimation forKey:@"enabledFloater"];
 }
 if (didAddSubview) {
  /* we already added the subview; return */
  return;
 }
 didAddSubview = 1;
if (![_preferences boolForKey:@"USE_TRANS_COLORS"]) {
 /* not enabled so return */
 return;
}
 didAddSubview = 1;
 CGRect gradientFrame = CGRectMake(0,0,self.frame.size.width,self.frame.size.height);
 GradientProgressView *gradientProgressView = [[GradientProgressView alloc]initWithFrame:gradientFrame];
 /* If this actually works I'm going to scream */
 UIView *ugh = [self superview];
 if (ugh) {
  NSArray *subviews = [ugh subviews];
  if (subviews) {
   UIView *subviewzero = subviews[0];
   if (subviewzero) {
    /* set frame to ourself */
    [gradientProgressView setFrame:CGRectMake(subviewzero.frame.origin.x, subviewzero.frame.origin.y, subviewzero.frame.size.width, subviewzero.frame.size.height)];
   }
  }
  [ugh insertSubview:gradientProgressView atIndex:0];
  if ([_preferences boolForKey:@"enabledFloater"]) {
  /* add the same floating label anim */
  CABasicAnimation *floatingLabelAnimation = [CABasicAnimation animationWithKeyPath:@"position.y"];
  floatingLabelAnimation.fromValue = [NSNumber numberWithDouble:(gradientProgressView.frame.origin.y + 500)];
  floatingLabelAnimation.toValue = [NSNumber numberWithDouble:(gradientProgressView.frame.origin.y - -200)];
  floatingLabelAnimation.duration = 5;
  floatingLabelAnimation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
  floatingLabelAnimation.autoreverses = YES;
  floatingLabelAnimation.repeatCount = INFINITY;
  [gradientProgressView.layer addAnimation:floatingLabelAnimation forKey:@"enabledFloater"];

  CABasicAnimation* gradRot = [CABasicAnimation animationWithKeyPath:@"transform.rotation"];
  [gradRot setDuration:2.5];
  [gradRot setFromValue:@0.3];
  [gradRot setToValue:@-0.3];
  gradRot.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
  [gradRot setRepeatCount:INFINITY];
  [gradRot setAutoreverses:YES];
  [gradientProgressView.layer addAnimation:gradRot forKey:@"GradientProgressViewRotation"];
  }
 }
 /* we have added the GradientProgressView to ourselves */
 /* now, lets start the animation... */
 CGFloat setCornerRadius = [_preferences floatForKey:@"cornerRadius"];
 gradientProgressView.layer.cornerRadius = setCornerRadius;
 [gradientProgressView setProgress:100.0];
 [gradientProgressView setAlpha:1.0];
 [gradientProgressView setUserInteractionEnabled:NO];
 [gradientProgressView startAnimating];

 CABasicAnimation* rotAnimation = [CABasicAnimation animationWithKeyPath:@"transform.rotation"];
 [rotAnimation setDuration:2.5];
 [rotAnimation setFromValue:@0.3];
 [rotAnimation setToValue:@-0.3];
 rotAnimation.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseInEaseOut];
 [rotAnimation setRepeatCount:INFINITY];
 [rotAnimation setAutoreverses:YES];
 [self.layer addAnimation:rotAnimation forKey:@"SBFLockScreenDateViewRotation"];
}

-(instancetype)initWithFrame:(CGRect)frame {
 /* run the original code */
 /* Not done yet
 NSString *mainFont = [_preferences objectForKey:@"mainFont"];
 NSString *subFont = [_preferences objectForKey:@"subFont"];
 */
 id returnedFromOriginalMethod = %orig;
 if (returnedFromOriginalMethod) {
  /* set the font */
  SBUILegibilityLabel *timeLabel = [returnedFromOriginalMethod valueForKey:@"_timeLabel"];
  if (timeLabel) {
   timeLabel.font = [UIFont fontWithName:@"AcademyEngravedLetPlain" size:timeLabel.font.pointSize];
  }
  /* set the font for date label */
  SBFLockScreenDateSubtitleDateView *dateSubtitleView = [returnedFromOriginalMethod valueForKey:@"_dateSubtitleView"];
  if (dateSubtitleView) {
   SBUILegibilityLabel *dateLabel = dateSubtitleView.subviews[0];
   if (dateLabel) {
    dateLabel.font = [UIFont fontWithName:@"AcademyEngravedLetPlain" size:dateLabel.font.pointSize ];
   }
  }
 }
 return returnedFromOriginalMethod;
}

/* Seems like the date view (should) always be index 0, with subtitle being below */
-(NSArray *)subviews {
 NSArray *subviews = %orig;
 NSString *textColorNew = [_preferences objectForKey:@"textColorTwo"];
 SBUILegibilityLabel *daLabel = subviews[0];
 /* The good shit */
 /* So I toyed around with SBUILegibilityLabel */
 /* And found that the reason why it keeps overriding textColor is because it is paying attention to it's _UILegibilitySettings ivar */
 /* So, instead of changing textColor, we change UILegibilitySettings */

 /* Get the settings */
 UIColor *origPrimaryColor = daLabel.legibilitySettings.primaryColor;
 if (textColorNew) {
   daLabel.legibilitySettings.primaryColor = colorFromHexString(textColorNew);
 }

 /* Declare our NSStrings for Prefs */

 /* Now, update the label for our settings */
 [daLabel _updateLegibilityView];
 /* Restore old legibilitySettings, for some reason status bar will use it ??? */
 daLabel.legibilitySettings.primaryColor = origPrimaryColor;

 /* Purple Glow Demo */
 NSString *shadowColorString = [_preferences objectForKey:@"bananas"];
 daLabel.layer.shadowOffset = CGSizeMake(0,0);
 if (shadowColorString) {
 daLabel.layer.shadowColor = colorFromHexString(shadowColorString).CGColor;
 }
 CGFloat setShadowRadius = [_preferences floatForKey:@"shadowRadius"];
 if (!(setShadowRadius >= 0)){
    setShadowRadius = 1;
 }
 daLabel.layer.shadowRadius = setShadowRadius;
 daLabel.layer.shadowOpacity = 1.0;

 return subviews;
}
%end

%hook SBFLockScreenDateSubtitleDateView
-(NSArray *)subviews {
 NSArray *subviews = %orig;
 NSString *textColorTwo = [_preferences objectForKey:@"textColorTwo"];
 SBUILegibilityLabel *daLabel = subviews[0];
 
 UIColor *oldPrimaryColor = daLabel.legibilitySettings.primaryColor;
 if (textColorTwo) {
 daLabel.legibilitySettings.primaryColor = colorFromHexString(textColorTwo);
 }

 [daLabel _updateLegibilityView];
 [daLabel viewForFirstBaselineLayout]; /* uhhh idk what this does... i don't remember adding it... leaving here in case it's important? */
 /* Restore old legibilitySettings, for some reason status bar will use it ??? */
 daLabel.legibilitySettings.primaryColor = oldPrimaryColor;

 daLabel.layer.shadowOffset = CGSizeMake(0,0);
 NSString *textShadow = [_preferences objectForKey:@"shadowColor2"];
 if (textShadow) {
 daLabel.layer.shadowColor = colorFromHexString(textShadow).CGColor;
 }
 CGFloat setShadowRadius = [_preferences floatForKey:@"shadowRadius"];
 if (!(setShadowRadius >= 0)){
    setShadowRadius = 1;
  }
  daLabel.layer.shadowRadius = setShadowRadius;
 daLabel.layer.shadowOpacity = 1.0;

 return subviews;
}
%end

%hook MRUNowPlayingView
-(void)didMoveToWindow { //TODO: If there is a better method (didMoveToSuperview will prob be better since we are messing with the superview associated with it and that is called once the view gets added, but using this just to be extra safe for now
 //safety check just in case
 if (!self) {
  //this should never happen, but just in case the world explodes...
  return;
 }
 UIView *firstSuperview = self.superview;
 if (!firstSuperview) {
  return;
 }
 // firstSuperview holds MRUNowPlayingView as a subview
 UIView *controlsView = firstSuperview.superview;
 if (!controlsView) {
  return;
 }
 // thats the second superview
 UIView *thirdSuperview = controlsView.superview;
 if (!thirdSuperview) {
  return;
 }
 UIView *platterView = thirdSuperview.superview;
 if (!platterView) {
  return;
 }
 // ok so we have the superview that holds the thirdSuperview and the MTMaterialView we wanna change
 // maybe the MTMaterialView is at a specific index which would be a bit faster but no time for that
 for (UIView *daView in platterView.subviews) {
  if ([daView isMemberOfClass:%c(MTMaterialView)]) {
   //WE GOT THE FUCKING MATERIAL VIEW
   //HOPE TO GOD THAT THERE WILL NEVER BE TWO MATERIALS HERE BECAUSE IF SO WE FUCKED UP LMAOOO
   //anyways, change time
   UIView *daMaterialView = daView;
   //oh, by the way, if you're wondering why daMaterialView.borderColor changes daView.borderColor even though it's a new variable...
   //this is because daView is just a pointer to a view
   //same with daMaterialView. when we make a new variable here, we aren't actually making a new view, we are setting our new pointer to point to the same view in memory as daView.
   //anyways, borderColor change time
   daMaterialView.layer.borderColor = [UIColor systemPinkColor].CGColor;
   daMaterialView.layer.borderWidth = 3;
  }
 }
}
%end

/*
Init prefs
*/

%ctor {
	_preferences = [[NSUserDefaults alloc] initWithSuiteName:@"gay.kota.kls"];
	[_preferences registerDefaults:@{
	@"enabled" : @YES,
    @"customTextUnlock": @"",
    @"cornerRadius": @0,
	}];
	_enabled = [_preferences boolForKey:@"enabled"];
	if(_enabled) {
        
		NSLog(@"[KLS] Enabled");
		%init();
	} else {
		NSLog(@"[KLS] Disabled, bye!");
	}
}
