/*
Kota LockScreen
*/

#include "kls.h"

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
BOOL forceCepheiPrefsWhichIReallyNeedToAccessAndIKnowWhatImDoingISwear;


%hook HBForceCepheiPrefs
+ (BOOL)forceCepheiPrefsWhichIReallyNeedToAccessAndIKnowWhatImDoingISwear {
    return YES;
}
%end
/* 
%hook CSTeachableMomentsContainerView
- (void)_layoutCallToActionLabel{
  id enabled = [_preferences objectForKey:@"enabled"];
	NSString *customText = [_preferences objectForKey:@"customTextUnlock"];
  NSUInteger characterCount = [customText length];
  if ([enabled isEqual:@1] && characterCount > 0){
	NSCharacterSet *set = [NSCharacterSet whitespaceCharacterSet];
	if ([[customText stringByTrimmingCharactersInSet: set] length] == 0) {
			customText = @"";
 }
}
 UILabel *label = [self callToActionLabel];
 if (label) {
  label.string = customText;
 }
}
%end
*/
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
/* Seems like the date view (should) always be index 0, with subtitle being below */
-(NSArray *)subviews {
 NSArray *subviews = %orig;
 NSString *textColorNew = [_preferences objectForKey:@"textColorNew"];
 SBUILegibilityLabel *daLabel = subviews[0];
 /* The good shit */
 /* So I toyed around with SBUILegibilityLabel */
 /* And found that the reason why it keeps overriding textColor is because it is paying attention to it's _UILegibilitySettings ivar */
 /* So, instead of changing textColor, we change UILegibilitySettings */

 /* Get the settings */
 if (textColorNew) {
   daLabel.legibilitySettings.primaryColor = colorFromHexString(textColorNew);
 }

 /* Declare our NSStrings for Prefs */

 /* Now, update the label for our settings */
 [daLabel _updateLabelForLegibilitySettings];
 [daLabel _updateLegibilityView];

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
 
 if (textColorTwo) {
 daLabel.legibilitySettings.primaryColor = colorFromHexString(textColorTwo);
 }

 [daLabel _updateLabelForLegibilitySettings];
 [daLabel _updateLegibilityView];
 [daLabel viewForFirstBaselineLayout];

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

/*
Init prefs
*/

%ctor {
	_preferences = [[NSUserDefaults alloc] initWithSuiteName:@"gay.kota.kls"];
	[_preferences registerDefaults:@{
		@"enabled" : @YES,
    @"customTextUnlock": @"",
	}];
	_enabled = [_preferences boolForKey:@"enabled"];
	if(_enabled) {
        
		NSLog(@"[KLS] Enabled");
		%init();
	} else {
		NSLog(@"[KLS] Disabled, bye!");
	}
}
