#include <UIKit/UIKit.h>

/*

Header(s) *meow*

*/

@class UILabel, SBUILegibilityLabel, SBFLockScreenDateSubtitleDateView, SBFLockScreenDateSubtitleView, NSHashTable, NSDate, UIColor, _UILegibilitySettings, NSString;

@interface BSUICAPackageView : UIView {
	CALayer* _rootLayer;
	CGSize _originalSize;
	NSString* _pendingCompletionToState;
	NSString* _pendingCompletionFromState;
	NSDictionary* _publishedObjectMap;
}
@property (nonatomic,copy,readonly) NSArray * publishedObjectNames; 
+(id)packageViewForActivity:(id)arg1 ;
-(void)layoutSubviews;
-(BOOL)setState:(id)arg1 ;
-(id)initWithPackageName:(id)arg1 inBundle:(id)arg2 ;
-(CGSize)sizeThatFits:(CGSize)arg1 ;
-(void)stateController:(id)arg1 transitionDidStop:(id)arg2 completed:(BOOL)arg3 ;
-(id)publishedObjectWithName:(id)arg1 ;
-(NSArray *)publishedObjectNames;
-(void)stateController:(id)arg1 transitionDidStart:(id)arg2 speed:(float)arg3 ;
-(void)stateController:(id)arg1 didSetStateOfLayer:(id)arg2 ;
-(BOOL)setState:(id)arg1 animated:(BOOL)arg2 ;
-(BOOL)setState:(id)arg1 animated:(BOOL)arg2 transitionSpeed:(double)arg3 completion:(/*^block*/id)arg4 ;
-(BOOL)setState:(id)arg1 onLayer:(id)arg2 animated:(BOOL)arg3 transitionSpeed:(double)arg4 completion:(/*^block*/id)arg5 ;
@end

@interface SBFLockScreenDateView : UIView {
	SBUILegibilityLabel* _timeLabel;
	double _timeAlpha;
	double _subtitleAlpha;
	NSHashTable* _replicatedViews;
	BOOL _useCompactDateFormat;
	NSDate* _date;
	UIColor* _overrideTextColor;
	double _alignmentPercent;
	double _dateToTimeStretch;
	double _timeLegibilityStrength;
	double _subtitleLegibilityStrength;
}
@property (assign,nonatomic) BOOL useCompactDateFormat;                                       //@synthesize useCompactDateFormat=_useCompactDateFormat - In the implementation block
@property (nonatomic,retain) NSDate * date;                                                   //@synthesize date=_date - In the implementation block
@property (nonatomic,retain) UIColor * textColor;                                             //@synthesize overrideTextColor=_overrideTextColor - In the implementation block
@property (nonatomic,retain) _UILegibilitySettings * legibilitySettings;                      //@synthesize legibilitySettings=_legibilitySettings - In the implementation block
@property (assign,nonatomic) double timeLegibilityStrength;                                   //@synthesize timeLegibilityStrength=_timeLegibilityStrength - In the implementation block
@property (assign,nonatomic) double subtitleLegibilityStrength;                               //@synthesize subtitleLegibilityStrength=_subtitleLegibilityStrength - In the implementation block
@property (assign,nonatomic) double alignmentPercent;                                         //@synthesize alignmentPercent=_alignmentPercent - In the implementation block
@property (assign,nonatomic) double dateToTimeStretch;                                        //@synthesize dateToTimeStretch=_dateToTimeStretch - In the implementation block
@property (nonatomic,readonly) double timeBaselineOffsetFromOrigin; 
@property (nonatomic,readonly) double subtitleBaselineOffsetFromOrigin; 
@property (nonatomic,readonly) double contentAlpha; 
@property (nonatomic,retain) SBFLockScreenDateSubtitleView * customSubtitleView;              //@synthesize customSubtitleView=_customSubtitleView - In the implementation block
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
+(double)defaultHeight;
+(id)timeFont;
-(id)initWithFrame:(CGRect)arg1 ;
-(void)layoutSubviews;
-(void)traitCollectionDidChange:(id)arg1 ;
-(void)setTextColor:(UIColor *)arg1 ;
-(NSDate *)date;
-(UIColor *)textColor;
-(void)setDate:(NSDate *)arg1 ;
-(id)replicate;
-(void)setAlignmentPercent:(double)arg1 ;
-(void)setUseCompactDateFormat:(BOOL)arg1 ;
-(double)alignmentPercent;
-(BOOL)useCompactDateFormat;
-(void)updateFormat;
-(void)_setSubtitleAlpha:(double)arg1 ;
-(void)_updateUsesCompactDateFormat;
-(void)_updateLabelAlpha;
-(void)setTimeLegibilityStrength:(double)arg1 ;
-(void)setSubtitleLegibilityStrength:(double)arg1 ;
-(void)setCustomSubtitleView:(SBFLockScreenDateSubtitleView *)arg1 ;
-(CGRect)_timeLabelFrameForAlignmentPercent:(double)arg1 ;
-(CGRect)_subtitleViewFrameForView:(id)arg1 alignmentPercent:(double)arg2 ;
-(UIEdgeInsets)_timeLabelInsetsForTimeString:(id)arg1 ;
-(UIEdgeInsets)_cachedGlyphInsetsTimeFontForString:(id)arg1 ;
-(BOOL)isSubtitleHidden;
-(void)setSubtitleHidden:(BOOL)arg1 ;
-(void)setDateToTimeStretch:(double)arg1 ;
-(void)setContentAlpha:(double)arg1 withSubtitleVisible:(BOOL)arg2 ;
-(CGRect)presentationExtentForAlignmentPercent:(double)arg1 ;
-(double)timeBaselineOffsetFromOrigin;
-(double)subtitleBaselineOffsetFromOrigin;
-(double)dateToTimeStretch;
-(double)timeLegibilityStrength;
-(double)subtitleLegibilityStrength;
-(double)contentAlpha;
-(id)_timeLabel;
-(void)_updateLabels;
@end

@class NSDate, SBFLockScreenAlternateDateLabel;

@interface SBFLockScreenDateSubtitleDateView : UIView {

	BOOL _useCompactDateFormat;
	NSDate* _date;
	SBFLockScreenAlternateDateLabel* _alternateDateLabel;
	double _alignmentPercent;
}
@property (nonatomic,retain) SBFLockScreenAlternateDateLabel * alternateDateLabel;              //@synthesize alternateDateLabel=_alternateDateLabel - In the implementation block
@property (assign,nonatomic) double alignmentPercent;                                           //@synthesize alignmentPercent=_alignmentPercent - In the implementation block
@property (nonatomic,retain) NSDate * date;                                                     //@synthesize date=_date - In the implementation block
@property (assign,nonatomic) BOOL useCompactDateFormat;                                         //@synthesize useCompactDateFormat=_useCompactDateFormat - In the implementation block
+(id)dateTimeLunarDateFont;
+(double)scaledFontSize:(double)arg1 withMaximumFontSizeCategory:(id)arg2 ;
+(double)subtitleLabelToLunarDateLabelBaselineDifferenceY;
-(id)initWithDate:(id)arg1 ;
-(void)layoutSubviews;
-(void)dealloc;
-(CGSize)sizeThatFits:(CGSize)arg1 ;
-(void)traitCollectionDidChange:(id)arg1 ;
-(NSDate *)date;
-(void)setDate:(NSDate *)arg1 ;
-(void)setLegibilitySettings:(id)arg1 ;
-(void)setStrength:(double)arg1 ;
-(id)replicate;
-(void)_setupAlternateDateLabel;
-(void)_updateDateLabelForCompact;
-(void)setAlignmentPercent:(double)arg1 ;
-(CGRect)alternateDateLabelFrame;
-(double)_lunarDateLabelYOffsetFromDateLabel;
-(CGRect)subtitleLabelFrame;
-(void)setUseCompactDateFormat:(BOOL)arg1 ;
-(id)_createReplicateView;
-(SBFLockScreenAlternateDateLabel *)alternateDateLabel;
-(void)setAlternateDateLabel:(SBFLockScreenAlternateDateLabel *)arg1 ;
-(double)alignmentPercent;
-(BOOL)useCompactDateFormat;
@end

@protocol NCNotificationStructuredListViewControllerDelegate, NCNotificationListCoalescingControlsHandler;
@class NCNotificationMasterList, NCNotificationListView, NCNotificationListTouchEaterManager, NCNotificationManagementViewPresenter, NCNotificationRequest, NCNotificationViewController, NCNotificationListSectionHeaderView, NSHashTable, UIScrollView, NSString, UIPanGestureRecognizer;

@interface NCNotificationStructuredListViewController : UIView {
	BOOL _deviceAuthenticated;
	BOOL _backgroundBlurred;
	double _itemSpacing;
	NCNotificationMasterList* _masterList;
	NCNotificationListView* _masterListView;
	NCNotificationListTouchEaterManager* _touchEaterManager;
	NCNotificationManagementViewPresenter* _managementViewPresenter;
	NCNotificationRequest* _notificationRequestRemovedWhilePresentingLongLook;
	NCNotificationViewController* _notificationViewControllerPresentingLongLook;
	NCNotificationListSectionHeaderView* _headerViewInForceTouchState;
	id<NCNotificationListCoalescingControlsHandler> _coalescingControlsHandlerInForceTouchState;
	NSHashTable* _observers;
	UIEdgeInsets _insetMargins;
}
@property (nonatomic,retain) NCNotificationMasterList * masterList;                                                                          //@synthesize masterList=_masterList - In the implementation block
@property (nonatomic,retain) NCNotificationListView * masterListView;                                                                        //@synthesize masterListView=_masterListView - In the implementation block
@property (nonatomic,retain) NCNotificationListTouchEaterManager * touchEaterManager;                                                        //@synthesize touchEaterManager=_touchEaterManager - In the implementation block
@property (nonatomic,retain) NCNotificationManagementViewPresenter * managementViewPresenter;                                                //@synthesize managementViewPresenter=_managementViewPresenter - In the implementation block
@property (assign,nonatomic) BOOL backgroundBlurred;                                                                                         //@synthesize backgroundBlurred=_backgroundBlurred - In the implementation block
@property (nonatomic,retain) NCNotificationRequest * notificationRequestRemovedWhilePresentingLongLook;                                      //@synthesize notificationRequestRemovedWhilePresentingLongLook=_notificationRequestRemovedWhilePresentingLongLook - In the implementation block
@property (nonatomic,retain) NSHashTable * observers;                                                                                        //@synthesize observers=_observers - In the implementation block
@property (nonatomic,readonly) UIScrollView * scrollView; 
@property (nonatomic,readonly) NSString * backgroundGroupNameBase; 
@property (nonatomic,readonly) CGSize effectiveContentSize; 
@property (nonatomic,readonly) UIEdgeInsets insetMargins;                                                                                    //@synthesize insetMargins=_insetMargins - In the implementation block
@property (nonatomic,readonly) double itemSpacing;                                                                                           //@synthesize itemSpacing=_itemSpacing - In the implementation block
@property (nonatomic,readonly) BOOL hasVisibleContent; 
@property (nonatomic,readonly) BOOL hasVisibleContentToReveal; 
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
-(void)notificationsLoadedForSectionIdentifier:(id)arg1 ;
-(void)listViewControllerPresentedByUserAction;
-(void)setDeviceAuthenticated:(BOOL)arg1 ;
-(BOOL)isPresentingNotificationInLongLook;
-(void)migrateNotifications;
-(void)_contentSizeCategoryDidChange;
-(void)adjustForLegibilitySettingsChange:(id)arg1 ;
-(NCNotificationViewController *)notificationViewControllerPresentingLongLook;
-(BOOL)interpretsViewAsContent:(id)arg1 ;
-(void)setMasterListView:(NCNotificationListView *)arg1 ;
-(void)removeNotificationRequest:(id)arg1 ;
-(void)expandGroupForNotificationRequest:(id)arg1 withCompletion:(/*^block*/id)arg2 ;
-(BOOL)isDeviceAuthenticated;
-(id)init;
-(void)notificationManagementViewPresenter:(id)arg1 setAllowsCriticalAlerts:(BOOL)arg2 forNotificationRequest:(id)arg3 withSectionIdentifier:(id)arg4 ;
-(void)insertNotificationRequest:(id)arg1 ;
-(void)toggleMissedSectionActive:(BOOL)arg1 reason:(unsigned long long)arg2 ;
-(id)notificationManagementViewPresenter:(id)arg1 sectionSettingsForSectionIdentifier:(id)arg2 ;
-(void)notificationListComponentRequestsClearingAllNotificationRequests:(id)arg1 ;
-(void)notificationListComponent:(id)arg1 didAddNotificationViewController:(id)arg2 ;
-(id)notificationRequestWithNotificationIdentifier:(id)arg1 sectionIdentifier:(id)arg2 ;
-(BOOL)isHomeAffordanceVisible;
-(void)notificationListComponent:(id)arg1 didEndUserInteractionWithNotificationViewController:(id)arg2 ;
-(void)setTouchEaterManager:(NCNotificationListTouchEaterManager *)arg1 ;
-(void)removeContentObserver:(id)arg1 ;
-(void)updateNotificationSectionSettings:(id)arg1 previousSectionSettings:(id)arg2 ;
-(UIEdgeInsets)insetMargins;
-(void)notificationManagementViewPresenter:(id)arg1 setDeliverQuietly:(BOOL)arg2 forNotificationRequest:(id)arg3 withSectionIdentifier:(id)arg4 ;
-(id)unhideHomeAffordanceAnimationSettingsForNotificationListComponent:(id)arg1 ;
-(void)modifyNotificationRequest:(id)arg1 ;
-(NSString *)backgroundGroupNameBase;
-(BOOL)hasVisibleContentToReveal;
-(void)setObservers:(NSHashTable *)arg1 ;
-(id)_sectionSettingsForSectionIdentifier:(id)arg1 ;
-(BOOL)notificationMasterListShouldAllowNotificationHistoryReveal:(id)arg1 ;
-(double)itemSpacing;
-(void)notificationMasterList:(id)arg1 requestsClearingFromIncomingSectionNotificationRequests:(id)arg2 ;
-(void)notificationListComponent:(id)arg1 didTransitionCoalescingControlsHandler:(id)arg2 toClearState:(BOOL)arg3 ;
-(id)settleHomeAffordanceAnimationBehaviorDescriptionForNotificationListComponent:(id)arg1 ;
-(void)notificationManagementViewPresenterDidDismissManagementView:(id)arg1 ;
-(void)setHomeAffordancePanGesture:(UIPanGestureRecognizer *)arg1 ;
-(NCNotificationListTouchEaterManager *)touchEaterManager;
-(id)notificationListComponent:(id)arg1 keyboardAssertionForGestureWindow:(id)arg2 ;
-(void)_didChangeDeepestUnambiguousResponder;
-(void)notificationListComponent:(id)arg1 didPresentCoalescingControlsHandler:(id)arg2 inForceTouchState:(BOOL)arg3 ;
-(UIScrollView *)scrollView;
-(void)notificationListComponent:(id)arg1 requestsClearingNotificationRequests:(id)arg2 ;
-(BOOL)backgroundBlurred;
@end

@protocol SBDashBoardHomeAffordanceAnimationViewProviding, SBUIBiometricResource;
@class CSHomeAffordanceViewController, NSTimer, NSMutableDictionary, UITapGestureRecognizer, CSTeachableMomentsContainerView, NSString;

@interface CSTeachableMomentsContainerViewController : UIView {

	BOOL _authenticated;
	BOOL _updateTextLabelOnNextAnimation;
	BOOL _controlCenterCoachingIsHidden;
	CSHomeAffordanceViewController* _homeAffordanceViewController;
	unsigned long long _animationState;
	id<SBDashBoardHomeAffordanceAnimationViewProviding> _viewProvider;
	id<SBUIBiometricResource> _biometricResource;
	NSTimer* _fireOffAnimationTimer;
	NSMutableDictionary* _cachedLegibilityLabels;
	UITapGestureRecognizer* _homeAffordanceClickGestureRecognizer;
}
@property (nonatomic,retain) NSTimer * fireOffAnimationTimer;                                                      //@synthesize fireOffAnimationTimer=_fireOffAnimationTimer - In the implementation block
@property (assign,nonatomic) BOOL authenticated;                                                                   //@synthesize authenticated=_authenticated - In the implementation block
@property (assign,nonatomic) BOOL updateTextLabelOnNextAnimation;
@property (nonatomic,copy) NSString * originalText;  
@property (nonatomic,copy) NSString * text;                                               //@synthesize originalText=_originalText - In the implementation block
@property (nonatomic,readonly) NSTimer * alternateTextTimer;                                         //@synthesize alternateTextTimer=_alternateTextTimer - In the implementation block
@property (assign,nonatomic) long long fontStyle;                                                    //@synthesize fontStyle=_fontStyle - In the implementation block
@property (assign,nonatomic) UIEdgeInsets alignmentRectInsets;                                       //@synthesize alignmentRectInsets=_alignmentRectInsets - In the implementation block
@property (nonatomic,copy) NSString * alternateText;                                                   //@synthesize updateTextLabelOnNextAnimation=_updateTextLabelOnNextAnimation - In the implementation block
@property (nonatomic,retain) NSMutableDictionary * cachedLegibilityLabels;                                         //@synthesize cachedLegibilityLabels=_cachedLegibilityLabels - In the implementation block
@property (assign,nonatomic) BOOL controlCenterCoachingIsHidden;                                                   //@synthesize controlCenterCoachingIsHidden=_controlCenterCoachingIsHidden - In the implementation block
@property (nonatomic,retain) UITapGestureRecognizer * homeAffordanceClickGestureRecognizer;                        //@synthesize homeAffordanceClickGestureRecognizer=_homeAffordanceClickGestureRecognizer - In the implementation block
@property (nonatomic,readonly) CSTeachableMomentsContainerView * teachableMomentsContainerView; 
@property (nonatomic,readonly) CSHomeAffordanceViewController * homeAffordanceViewController;                      //@synthesize homeAffordanceViewController=_homeAffordanceViewController - In the implementation block
@property (assign,nonatomic) unsigned long long animationState;                                                    //@synthesize animationState=_animationState - In the implementation block
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
-(unsigned long long)animationState;
-(void)setAlternateText:(NSString *)arg1 ;
-(void)setAuthenticated:(BOOL)arg1 ;
-(void)setViewProvider:(id<SBDashBoardHomeAffordanceAnimationViewProviding>)arg1 ;
-(id)init;
-(BOOL)gestureRecognizer:(id)arg1 shouldReceiveTouch:(id)arg2 ;
-(void)_updateLegibilitySettings;
-(void)loadView;
-(void)viewWillAppear:(BOOL)arg1 ;
-(unsigned long long)currentState;
-(void)animationDidStop:(id)arg1 finished:(BOOL)arg2 ;
-(void)aggregateAppearance:(id)arg1 ;
-(void)_setupTimer;
-(void)setAnimationState:(unsigned long long)arg1 ;
-(void)viewWillDisappear:(BOOL)arg1 ;
-(BOOL)authenticated;
-(CSTeachableMomentsContainerView *)teachableMomentsContainerView;
-(void)setBiometricResource:(id<SBUIBiometricResource>)arg1 ;
-(void)_contentSizeCategoryChanged;
-(CSHomeAffordanceViewController *)homeAffordanceViewController;
-(void)dealloc;
-(id<SBUIBiometricResource>)biometricResource;
-(BOOL)handleEvent:(id)arg1 ;
-(void)_updateTextLabel;
-(void)_updateText:(id)arg1 ;
-(void)_removeResetAnimationForKeyPath:(id)arg1 onLayer:(id)arg2 ;
-(void)_homeAffordanceClickRecognized:(id)arg1 ;
-(void)_setControlCenterTutorsHidden:(BOOL)arg1 ;
-(void)_moveUpTimerForFiringAfterDelay:(double)arg1 ;
-(void)setUpdateTextLabelOnNextAnimation:(BOOL)arg1 ;
-(void)_cancelTimerAndResetAnimation;
-(void)_setupTimerWithDelay:(double)arg1 ;
-(void)_updateTextLabelIfNeeded;
-(void)_addHomeAffordanceAnimation;
-(void)_addTextAnimation;
-(BOOL)_shouldTeachAboutControlCenter;
-(void)_addControlCenterGrabberAnimation;
-(void)_addControlCenterGlyphAnimation;
-(void)setFireOffAnimationTimer:(NSTimer *)arg1 ;
-(void)_addHomeAffordanceResetAnimation;
-(void)_addTextResetAnimation;
-(void)_addControlCenterGrabberResetAnimation;
-(void)_addControlCenterGlyphResetAnimation;
-(void)_removeNormalAnimationsForKeyPath:(id)arg1 onLayer:(id)arg2 ;
-(void)_addResetAnimationForKeyPath:(id)arg1 onLayer:(id)arg2 ;
-(id)_textPositionAnimationWithDuration:(double)arg1 beginTime:(double)arg2 ;
-(id)_textAlphaAnimationWithDuration:(double)arg1 beginTime:(double)arg2 ;
-(id)_controlCenterGrabberPositionAnimationWithDuration:(double)arg1 beginTime:(double)arg2 ;
-(id)_controlCenterGrabberAlphaAnimationWithDuration:(double)arg1 beginTime:(double)arg2 ;
-(id)_controlCenterGlyphAlphaAnimationWithDuration:(double)arg1 beginTime:(double)arg2 ;
-(BOOL)updateTextLabelOnNextAnimation;
-(void)setCachedLegibilityLabels:(NSMutableDictionary *)arg1 ;
-(BOOL)controlCenterCoachingIsHidden;
-(void)setControlCenterCoachingIsHidden:(BOOL)arg1 ;
@end

@interface SBUIProudLockContainerViewController : UIView {

	long long _desiredIconState;
	unsigned long long _desiredCoachingCondition;
	int _unlockSource;
	BOOL _authenticated;
	BOOL _screenOn;
	BOOL _suppressScanningState;
	BOOL _suppressNotLooking;
	BOOL _guidanceTextVisible;
	BOOL _canShowScanningState;
	BOOL _shouldShowScanningState;
	BOOL _canShowCoachingCondition;
	BOOL _canLeaveCoachingCondition;
	BOOL _hasSeenFaceSinceScreenOn;
	BOOL _canShowCameraCovered;
	_UILegibilitySettings* _legibilitySettings;
	unsigned long long _forceCount;

}
@property (nonatomic, strong, readwrite) UIColor *textColor;
@property (nonatomic, strong, readwrite) UIFont *font;
@property (assign,nonatomic) BOOL canShowScanningState;                                                                                        //@synthesize canShowScanningState=_canShowScanningState - In the implementation block
@property (assign,nonatomic) BOOL shouldShowScanningState;                                                                                     //@synthesize shouldShowScanningState=_shouldShowScanningState - In the implementation block
@property (assign,nonatomic) BOOL canShowCoachingCondition;                                                                                    //@synthesize canShowCoachingCondition=_canShowCoachingCondition - In the implementation block
@property (assign,nonatomic) BOOL canLeaveCoachingCondition;                                                                                   //@synthesize canLeaveCoachingCondition=_canLeaveCoachingCondition - In the implementation block
@property (assign,nonatomic) BOOL hasSeenFaceSinceScreenOn;                                                                                    //@synthesize hasSeenFaceSinceScreenOn=_hasSeenFaceSinceScreenOn - In the implementation block
@property (assign,nonatomic) BOOL canShowCameraCovered;                                                                                        //@synthesize canShowCameraCovered=_canShowCameraCovered - In the implementation block
@property (nonatomic,copy) id unlockCompletion;                                                                                                //@synthesize unlockCompletion=_unlockCompletion - In the implementation block
@property (assign,nonatomic) unsigned long long forceCount;                                                                                    //@synthesize forceCount=_forceCount - In the implementation block
@property (nonatomic,retain) _UILegibilitySettings * legibilitySettings;                                                                       //@synthesize legibilitySettings=_legibilitySettings - In the implementation block
@property (assign,getter=isAuthenticated,nonatomic) BOOL authenticated;                                                                        //@synthesize authenticated=_authenticated - In the implementation block
@property (assign,getter=isScreenOn,nonatomic) BOOL screenOn;                                                                                  //@synthesize screenOn=_screenOn - In the implementation block
@property (assign,nonatomic) BOOL suppressScanningState;                                                                                       //@synthesize suppressScanningState=_suppressScanningState - In the implementation block
@property (assign,nonatomic) BOOL suppressNotLooking;                                                                                          //@synthesize suppressNotLooking=_suppressNotLooking - In the implementation block
@property (nonatomic,readonly) UIView * cameraCoveredView; 
@property (assign,getter=isGuidanceTextVisible,nonatomic) BOOL guidanceTextVisible;                                                            //@synthesize guidanceTextVisible=_guidanceTextVisible - In the implementation block
@property (nonatomic,readonly) BOOL isPortrait; 
-(BOOL)isPortrait;
-(id)initWithAuthenticationInformationProvider:(id)arg1 ;
-(void)setSuppressScanningState:(BOOL)arg1 ;
-(void)setSuppressNotLooking:(BOOL)arg1 ;
-(void)updateLockForBiometricMatchFailure;
-(void)setAuthenticated:(BOOL)arg1 completion:(/*^block*/id)arg2 ;
-(void)handleBiometricEvent:(unsigned long long)arg1 ;
-(void)setScreenOn:(BOOL)arg1 ;
-(void)_setCounterTransformForOrientation:(long long)arg1 ;
-(void)_setLocalTransformForOrientation:(long long)arg1 ;
-(void)_updateIconViewStateAnimated:(BOOL)arg1 ;
-(void)_startScanningStateTimer;
-(id)_proudLockIconView;
-(unsigned long long)_effectiveCoachingConditionForCondition:(unsigned long long)arg1 orientation:(long long)arg2 ;
-(void)_setCoachingCondition:(unsigned long long)arg1 animated:(BOOL)arg2 force:(BOOL)arg3 ;
-(void)setScreenOn:(BOOL)arg1 fromUnlockSource:(int)arg2 ;
-(BOOL)_isBiometricLockedOut;
-(void)_allowCameraCoveredImmediately:(BOOL)arg1 ;
-(void)_allowCoachingConditionImmediately:(BOOL)arg1 ;
-(unsigned long long)_effectiveCoachingConditionForCondition:(unsigned long long)arg1 ;
-(void)_setCoachingCondition:(unsigned long long)arg1 animated:(BOOL)arg2 ;
-(void)setShouldShowScanningState:(BOOL)arg1 ;
-(void)_allowScanningState;
-(void)setCanShowScanningState:(BOOL)arg1 ;
-(void)_clearCoachingCondition;
-(void)_updateIconViewStateAnimated:(BOOL)arg1 force:(BOOL)arg2 completion:(/*^block*/id)arg3 ;
-(void)setCanLeaveCoachingCondition:(BOOL)arg1 ;
-(void)setCanShowCoachingCondition:(BOOL)arg1 ;
-(void)setHasSeenFaceSinceScreenOn:(BOOL)arg1 ;
-(void)setCanShowCameraCovered:(BOOL)arg1 ;
-(void)_performForcedUpdate:(/*^block*/id)arg1 ;
-(BOOL)suppressNotLooking;
-(void)_setIconState:(long long)arg1 animated:(BOOL)arg2 options:(long long)arg3 force:(BOOL)arg4 completion:(/*^block*/id)arg5 ;
-(void)_updateLockForMatchStarted;
-(void)_updateLockForFaceInView;
-(void)_dontCallThis_updateCoachingCondition:(unsigned long long)arg1 animated:(BOOL)arg2 ;
-(void)_dontCallThis_showLockIfNeededAnimated:(BOOL)arg1 force:(BOOL)arg2 completion:(/*^block*/id)arg3 ;
-(id)orientationProvider;
-(void)_setCoachingCondition:(unsigned long long)arg1 animated:(BOOL)arg2 skipScanningState:(BOOL)arg3 force:(BOOL)arg4 ;
-(BOOL)_canTransitionToState:(long long)arg1 ;
-(void)setUnlockCompletion:(id)arg1 ;
-(void)_allowLeavingCoachingCondition;
-(BOOL)isGuidanceTextVisible;
-(void)_updateScanningState;
-(void)_allowCoachingCondition;
-(BOOL)canShowCoachingCondition;
-(void)_reallyAllowCoachingConditionAnimated:(BOOL)arg1 ;
-(void)_reallyAllowCameraCovered;
-(BOOL)canShowCameraCovered;
-(void)_reallyAllowLeavingCoachingCondition;
-(void)updateForScreenWillTurnOff;
-(id)testProudLockIconView;
-(void)setTestProudLockIconView:(id)arg1 ;
-(BOOL)suppressScanningState;
-(void)setGuidanceTextVisible:(BOOL)arg1 ;
-(BOOL)canShowScanningState;
-(BOOL)shouldShowScanningState;
-(BOOL)canLeaveCoachingCondition;
-(BOOL)hasSeenFaceSinceScreenOn;
-(id)unlockCompletion;
-(unsigned long long)forceCount;
-(void)setForceCount:(unsigned long long)arg1 ;
-(void)_setIconState:(long long)arg1 animated:(BOOL)arg2 ;
-(BOOL)isScreenOn;
-(BOOL)isAuthenticated;
-(void)setAuthenticated:(BOOL)arg1 ;
-(void)viewWillAppear:(BOOL)arg1 ;
-(void)loadView;
-(void)reset;
-(void)viewDidLoad;
-(void)viewWillTransitionToSize:(CGSize)arg1 withTransitionCoordinator:(id)arg2 ;
-(void)setLegibilitySettings:(_UILegibilitySettings *)arg1 ;
-(void)setOrientationProvider:(id)arg1 ;
@end

@class UIView, BSUICAPackageView, SBUICAPackageView, NSSet, LAUIPearlGlyphView, SBUIFaceIDCoachingView, SBUIFaceIDCameraGlyphView, _UILegibilitySettings, UIColor;

@interface SBUIProudLockIconView : UIView {

	long long _state;
	UIView* _iconContainerView;
	SBUICAPackageView* _lockView;
	NSSet* _imageLayers;
	NSSet* _shadowImageLayers;
	NSSet* _shadowFilterLayers;
	LAUIPearlGlyphView* _lazy_pearlGlyphView;
	id _pearlGlyphViewSharedResources;
	SBUIFaceIDCoachingView* _lazy_faceIDCoachingView;
	BOOL _performingIncomingLayout;
	SBUIFaceIDCameraGlyphView* _cameraCoveredView;
	_UILegibilitySettings* _legibilitySettings;
	double _durationOnCameraCoveredGlyphBeforeCoaching;
	UIColor* _contentColor;
	UIColor* _textColor;
}
@property (nonatomic,retain) UIColor * contentColor;          
@property (nonatomic,retain) UIColor * textColor;                                    //@synthesize contentColor=_contentColor - In the implementation block
@property (nonatomic,retain) _UILegibilitySettings * legibilitySettings;                     //@synthesize legibilitySettings=_legibilitySettings - In the implementation block
@property (assign,nonatomic) double durationOnCameraCoveredGlyphBeforeCoaching;              //@synthesize durationOnCameraCoveredGlyphBeforeCoaching=_durationOnCameraCoveredGlyphBeforeCoaching - In the implementation block
@property (assign,nonatomic) long long state;                                                //@synthesize state=_state - In the implementation block
@property (nonatomic,readonly) SBUIFaceIDCameraGlyphView * cameraCoveredView;                //@synthesize cameraCoveredView=_cameraCoveredView - In the implementation block
-(id)fileNameForCurrentDevice;
-(void)_forEachLayerInHierarchy:(id)arg1 perform:(/*^block*/id)arg2 ;
-(void)_transitionToState:(long long)arg1 animated:(BOOL)arg2 options:(long long)arg3 completion:(/*^block*/id)arg4 ;
-(void)setState:(long long)arg1 animated:(BOOL)arg2 completion:(/*^block*/id)arg3 ;
-(void)setState:(long long)arg1 animated:(BOOL)arg2 options:(long long)arg3 completion:(/*^block*/id)arg4 ;
-(void)_configureShadowFromLegibilitySettings:(id)arg1 ;
-(id)_faceIDCoachingView;
-(SBUIFaceIDCameraGlyphView *)cameraCoveredView;
-(CGSize)_smallLockSize;
-(double)_lockToCoachingSpacing;
-(void)_resetPearlGlyphView;
-(void)_resetfaceIDCoachingView;
-(void)_resetCameraGlyphView;
-(id)_activeViewsForState:(long long)arg1 ;
-(id)_pearlGlyphView;
-(id)_alphaAnimationSettingsForTransitionFromViews:(id)arg1 andState:(long long)arg2 toViews:(id)arg3 andState:(long long)arg4 forIncomingViews:(BOOL)arg5 ;
-(double)_alphaForActiveViewForState:(long long)arg1 ;
-(CGAffineTransform)_incomingTransformForActiveView:(id)arg1 forState:(long long)arg2 ;
-(id)_transformAnimationSettingsForTransitionFromViews:(id)arg1 andState:(long long)arg2 toViews:(id)arg3 andState:(long long)arg4 forIncomingViews:(BOOL)arg5 ;
-(CGAffineTransform)_outgoingTransformForView:(id)arg1 fromState:(long long)arg2 ;
-(CGAffineTransform)_transformForActiveView:(id)arg1 forState:(long long)arg2 ;
-(id)_layoutAnimationSettingsForTransitionFromViews:(id)arg1 andState:(long long)arg2 toViews:(id)arg3 andState:(long long)arg4 ;
-(id)_defaultAnimationSettingsForTransitionFromViews:(id)arg1 andState:(long long)arg2 toViews:(id)arg3 andState:(long long)arg4 ;
-(CGAffineTransform)_zoomedTransform;
-(double)_scaleAmountForZoom;
-(CGSize)_smallLockSizeForTextSize:(id)arg1 ;
-(double)durationOnCameraCoveredGlyphBeforeCoaching;
-(void)setDurationOnCameraCoveredGlyphBeforeCoaching:(double)arg1 ;
-(void)setState:(long long)arg1 animated:(BOOL)arg2 ;
-(long long)state;
-(id)initWithFrame:(CGRect)arg1 ;
-(void)layoutSubviews;
-(void)setState:(long long)arg1 ;
-(_UILegibilitySettings *)legibilitySettings;
-(void)setLegibilitySettings:(_UILegibilitySettings *)arg1 ;
-(void)setContentColor:(UIColor *)arg1 ;
-(UIColor *)contentColor;
@end

@protocol SBFDateProviding;
@class _UILegibilitySettings, NSString;

@interface SBFLockScreenDateViewController : UIView {

	id _timerToken;
	BOOL _isVisible;
	id _minuteHandlerToken;
	BOOL _disablesUpdates;
	BOOL _screenOff;
	_UILegibilitySettings* _legibilitySettings;
	id<SBFDateProviding> _dateProvider;
}
@property (assign,nonatomic) BOOL screenOff;   
@property (nonatomic, strong, readwrite) UIColor *textColor;
@property (nonatomic, strong, readwrite) UIFont *font;                                       //@synthesize screenOff=_screenOff - In the implementation block
@property (assign,getter=isSubtitleHidden,nonatomic) BOOL subtitleHidden; 
@property (nonatomic,retain) _UILegibilitySettings * legibilitySettings;               //@synthesize legibilitySettings=_legibilitySettings - In the implementation block
@property (nonatomic,retain) id<SBFDateProviding> dateProvider;                        //@synthesize dateProvider=_dateProvider - In the implementation block
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
-(void)dealloc;
-(NSString *)description;
-(void)setView:(id)arg1 ;
-(void)loadView;
-(id)initWithNibName:(id)arg1 bundle:(id)arg2 ;
-(void)viewWillAppear:(BOOL)arg1 ;
-(void)willMoveToParentViewController:(id)arg1 ;
-(void)viewDidDisappear:(BOOL)arg1 ;
-(void)_updateView;
-(BOOL)_canShowWhileLocked;
-(void)_updateState;
-(_UILegibilitySettings *)legibilitySettings;
-(void)setLegibilitySettings:(_UILegibilitySettings *)arg1 ;
-(void)settings:(id)arg1 changedValueForKey:(id)arg2 ;
-(id)dateView;
-(void)_addObservers;
-(void)_stopUpdateTimer;
-(void)_startUpdateTimer;
-(id<SBFDateProviding>)dateProvider;
-(BOOL)isSubtitleHidden;
-(void)setSubtitleHidden:(BOOL)arg1 ;
-(void)setContentAlpha:(double)arg1 withSubtitleVisible:(BOOL)arg2 ;
-(void)setCustomSubtitleView:(id)arg1 ;
-(void)setDateProvider:(id<SBFDateProviding>)arg1 ;
-(id)dateViewIfExists;
-(void)_updateLegibilityStrength;
-(void)_updateFormatIfEnabled;
-(void)_updateFormat;
-(void)_handleTimeZoneChange;
-(void)updateTimeNow;
-(void)setScreenOff:(BOOL)arg1 ;
-(BOOL)screenOff;
@end

@interface _UILegibilitySettings : NSObject {
    long long _style;
    UIColor *_contentColor;
    UIColor *_primaryColor;
    UIColor *_secondaryColor;
    UIColor *_shadowColor;
    double _shadowRadius;
    double _shadowAlpha;
    double _imageOutset;
    NSString *_shadowCompositingFilterName;
}
+ (id)sharedInstanceForStyle:(long long)arg1;
@property(copy, nonatomic) NSString *shadowCompositingFilterName; // @synthesize
@property(nonatomic) double imageOutset; // @synthesize imageOutset=_imageOutset;
@property(nonatomic) double shadowAlpha; // @synthesize shadowAlpha=_shadowAlpha;
@property(nonatomic) double shadowRadius; // @synthesize shadowRadius=_shadowRadius;
@property(retain, nonatomic) UIColor *shadowColor; // @synthesize shadowColor=_shadowColor;
@property(retain, nonatomic) UIColor *secondaryColor; // @synthesize secondaryColor=_secondaryColor;
@property(retain, nonatomic) UIColor *primaryColor; // @synthesize primaryColor=_primaryColor;
@property(retain, nonatomic) UIColor *contentColor; // @synthesize contentColor=_contentColor;
@property(nonatomic) long long style; // @synthesize style=_style;
- (void)setPropertiesForStyle:(long long)arg1;
- (void)dealloc;
- (id)initWithStyle:(long long)arg1 primaryColor:(id)arg2 secondaryColor:(id)arg3 shadowColor:(id)arg4;
- (id)initWithStyle:(long long)arg1 contentColor:(id)arg2;
- (id)initWithContentColor:(id)arg1 contrast:(double)arg2;
- (id)initWithContentColor:(id)arg1;
- (id)initWithStyle:(long long)arg1;
@end

@interface SBUILegibilityLabel : UIView
@property (nonatomic, retain) _UILegibilitySettings *legibilitySettings;
-(void)_updateLabelForLegibilitySettings;
-(void)_updateLegibilityView;
@end