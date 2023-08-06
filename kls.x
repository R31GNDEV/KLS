/*
Kota LockScreen
*/

#include "kls.h"

UIColor* necksusSucksBalls(NSString* hexString) {
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

%hook NCNotificationStructuredListViewController

%end
*/

%hook SBFLockScreenDateView
/* Seems like the date view (should) always be index 0, with subtitle being below */
-(CALayer *)layer {
  CALayer *origLayer = %orig;
  NSString *glowColorString = [_preferences objectForKey:@"shadowColor"];
  NSString *backColorString = [_preferences objectForKey:@"backColor"];
  CGFloat setCornerRadius = [_preferences floatForKey:@"cornerRadius"];
  if (!(setCornerRadius >= 0)){
    setCornerRadius = 1;
  }
  origLayer.cornerRadius = setCornerRadius;
  if (glowColorString) {
    origLayer.shadowColor = necksusSucksBalls(glowColorString).CGColor;
  }
  if (backColorString) {
    origLayer.backgroundColor = necksusSucksBalls(backColorString).CGColor;
  }
  origLayer.shadowOpacity = 1;
  origLayer.shadowOffset = CGSizeMake(0.0f,4.0f);
  return origLayer;
}

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
   daLabel.legibilitySettings.primaryColor = necksusSucksBalls(textColorNew);
 }

 /* Declare our NSStrings for Prefs */

 /* Now, update the label for our settings */
 [daLabel _updateLabelForLegibilitySettings];
 [daLabel _updateLegibilityView];

 /* Purple Glow Demo */

 daLabel.layer.shadowOffset = CGSizeMake(0,0);
 daLabel.layer.shadowColor = [UIColor purpleColor].CGColor;
 daLabel.layer.shadowOpacity = 1.0;

 return subviews;
}
%end

%hook SBFLockScreenDateSubtitleDateView
-(NSArray *)subviews {
 NSArray *subviews = %orig;
 NSString *textColorTwo = [_preferences objectForKey:@"textColorTwo"];
 SBUILegibilityLabel *daLabel = subviews[0];
 /* The good shit */
 /* So I toyed around with SBUILegibilityLabel */
 /* And found that the reason why it keeps overriding textColor is because it is paying attention to it's _UILegibilitySettings ivar */
 /* So, instead of changing textColor, we change UILegibilitySettings */

 /* Get the settings */
 if (textColorTwo) {
 daLabel.legibilitySettings.primaryColor = necksusSucksBalls(textColorTwo);
 }

 /* Now, update the label for our settings */
 [daLabel _updateLabelForLegibilitySettings];
 [daLabel _updateLegibilityView];

 /* Purple Glow Demo */

 daLabel.layer.shadowOffset = CGSizeMake(0,0);
 daLabel.layer.shadowColor = [UIColor purpleColor].CGColor;
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
	}];
	_enabled = [_preferences boolForKey:@"enabled"];
	if(_enabled) {
        
		NSLog(@"[KLS] Enabled");
		%init();
	} else {
		NSLog(@"[KLS] Disabled, bye!");
	}
}