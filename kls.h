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

@class NSString, SBUILegibilityLabel, UIImageView, UIStatusBar, UIView, _UILegibilitySettings;

@interface CSTeachableMomentsContainerView : UIView
{
    _UILegibilitySettings *_legibilitySettings;
    UIView *_controlCenterGrabberView;
    UIView *_controlCenterGrabberPositionPlaceholderView;
    UIImageView *_controlCenterGlyphView;
    SBUILegibilityLabel *_callToActionLabel;
    UIView *_callToActionLabelPositionPlaceholderView;
    UIStatusBar *_statusBarToFollow;
    UIView *_controlCenterGrabberEffectContainerView;
    UIView *_controlCenterTutorsContainerView;
    UIView *_controlCenterGrabberContainerView;
    UIView *_controlCenterGlyphContainerView;
    UIView *_callToActionLabelContainerView;
    UIView *_homeAffordanceContainerView;
    UIView *_homeAffordanceView;
}

@property(retain, nonatomic) UIView *homeAffordanceView; // @synthesize homeAffordanceView=_homeAffordanceView;
@property(retain, nonatomic) UIView *homeAffordanceContainerView; // @synthesize homeAffordanceContainerView=_homeAffordanceContainerView;
@property(retain, nonatomic) UIView *callToActionLabelContainerView; // @synthesize callToActionLabelContainerView=_callToActionLabelContainerView;
@property(retain, nonatomic) UIView *controlCenterGlyphContainerView; // @synthesize controlCenterGlyphContainerView=_controlCenterGlyphContainerView;
@property(retain, nonatomic) UIView *controlCenterGrabberContainerView; // @synthesize controlCenterGrabberContainerView=_controlCenterGrabberContainerView;
@property(retain, nonatomic) UIView *controlCenterTutorsContainerView; // @synthesize controlCenterTutorsContainerView=_controlCenterTutorsContainerView;
@property(retain, nonatomic) UIView *controlCenterGrabberEffectContainerView; // @synthesize controlCenterGrabberEffectContainerView=_controlCenterGrabberEffectContainerView;
@property(retain, nonatomic) UIView *callToActionLabelPositionPlaceholderView; // @synthesize callToActionLabelPositionPlaceholderView=_callToActionLabelPositionPlaceholderView;
@property(retain, nonatomic) SBUILegibilityLabel *callToActionLabel; // @synthesize callToActionLabel=_callToActionLabel;
@property(retain, nonatomic) UIImageView *controlCenterGlyphView; // @synthesize controlCenterGlyphView=_controlCenterGlyphView;
@property(retain, nonatomic) UIView *controlCenterGrabberPositionPlaceholderView; // @synthesize controlCenterGrabberPositionPlaceholderView=_controlCenterGrabberPositionPlaceholderView;
@property(retain, nonatomic) UIView *controlCenterGrabberView; // @synthesize controlCenterGrabberView=_controlCenterGrabberView;
@property(retain, nonatomic) _UILegibilitySettings *legibilitySettings; // @synthesize legibilitySettings=_legibilitySettings;
- (id)_callToActionLabelFont;
- (void)_preferredTextSizeChanged:(id)arg1;
- (struct CGPoint)_grabberCenterForCointainerBounds:(struct CGRect)arg1 grabberTop:(double)arg2 grabberSize:(struct CGSize)arg3;
- (void)_layoutControlCenterGrabberAndGlyph;
- (void)_layoutCallToActionLabel;
- (void)_layoutHomeAffordanceContainer;
- (void)_addControlCenterTutors;
- (void)_addCallToActionLabel;
- (id)createCallToActionLabel;
- (void)_updateViewsForLegibilitySettings;
- (id)presentationRegions;
- (void)layoutSubviews;
- (id)initWithFrame:(struct CGRect)arg1;
-(NSString *)text;
-(SBUILegibilityLabel *)label;
-(void)setLabel:(SBUILegibilityLabel *)textLabel;
-(void)setText:(NSString *)arg1 ;

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
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

@class UILabel, _UILegibilityView, NSArray, UILayoutGuide, NSString, UIFont, NSAttributedString, UIColor, _UILegibilitySettings;

@interface SBUILegibilityLabel : UIView {

	UILabel* _lookasideLabel;
	_UILegibilityView* _legibilityView;
	BOOL _isDirty;
	double _strength;
	long long _options;
	double _scale;
	NSArray* _legibilityConstraints;
	UILayoutGuide* _firstBaselineLayoutGuide;
	UILayoutGuide* _lastBaselineLayoutGuide;
	NSString* _string;
	UIFont* _font;
	NSAttributedString* _attributedText;
	UIColor* _textColorOverride;
	_UILegibilitySettings* _legibilitySettings;
	BOOL _isWaitingToMoveToWindow;
}
@property (nonatomic,copy) NSAttributedString * attributedText;                       //@synthesize attributedText=_attributedText - In the implementation block
@property (nonatomic,copy) NSString * string;                                         //@synthesize string=_string - In the implementation block
@property (nonatomic,copy) UIColor * textColor; 
@property (nonatomic,retain) UIFont * font;                                           //@synthesize font=_font - In the implementation block
@property (assign,nonatomic) long long numberOfLines; 
@property (assign,nonatomic) BOOL adjustsFontSizeToFitWidth; 
@property (assign,nonatomic) double minimumScaleFactor; 
@property (assign,nonatomic) long long textAlignment; 
@property (assign,nonatomic) long long lineBreakMode; 
@property (assign,nonatomic) BOOL useColorFilters; 
@property (nonatomic,readonly) UIEdgeInsets characterOverflowInsets; 
@property (nonatomic,readonly) double firstBaselineOffsetFromBottom; 
@property (nonatomic,readonly) double lastBaselineOffsetFromBottom; 
@property (nonatomic,readonly) double baselineOffset; 
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
@property (nonatomic,retain) _UILegibilitySettings * legibilitySettings; 
@property (assign,nonatomic) double strength;                                         //@synthesize strength=_strength - In the implementation block
-(id)initWithFrame:(CGRect)arg1 ;
-(void)setFrame:(CGRect)arg1 ;
-(void)setNumberOfLines:(long long)arg1 ;
-(void)setTextAlignment:(long long)arg1 ;
-(void)setAttributedText:(NSAttributedString *)arg1 ;
-(void)layoutSubviews;
-(id)initWithCoder:(id)arg1 ;
-(void)didMoveToWindow;
-(void)setBounds:(CGRect)arg1 ;
-(CGSize)sizeThatFits:(CGSize)arg1 ;
-(void)setFont:(UIFont *)arg1 ;
-(void)setTextColor:(UIColor *)arg1 ;
-(NSString *)string;
-(void)setString:(NSString *)arg1 ;
-(void)setLineBreakMode:(long long)arg1 ;
-(void)setOptions:(long long)arg1 ;
-(UIFont *)font;
-(UIColor *)textColor;
-(long long)textAlignment;
-(NSAttributedString *)attributedText;
-(long long)lineBreakMode;
-(void)setAdjustsFontSizeToFitWidth:(BOOL)arg1 ;
-(id)viewForLastBaselineLayout;
-(double)baselineOffset;
-(void)setMinimumScaleFactor:(double)arg1 ;
-(double)minimumScaleFactor;
-(long long)numberOfLines;
-(BOOL)adjustsFontSizeToFitWidth;
-(void)setLegibilitySettings:(_UILegibilitySettings *)arg1 ;
-(_UILegibilitySettings *)legibilitySettings;
-(id)viewForFirstBaselineLayout;
-(double)strength;
-(void)setStrength:(double)arg1 ;
-(id)initWithSettings:(id)arg1 strength:(double)arg2 string:(id)arg3 font:(id)arg4 options:(long long)arg5 ;
-(id)initWithSettings:(id)arg1 strength:(double)arg2 string:(id)arg3 font:(id)arg4 ;
-(void)_updateLegibilityView;
-(UIEdgeInsets)characterOverflowInsets;
-(void)setUseColorFilters:(BOOL)arg1 ;
-(double)firstBaselineOffsetFromBottom;
-(void)_markOurselfDirty;
-(double)_layoutGuideOffsetFromBottom:(id)arg1 ;
-(BOOL)useColorFilters;
-(void)_updateLabelForLegibilitySettings;
-(BOOL)_needsColorImage;
-(double)lastBaselineOffsetFromBottom;
-(id)initWithSettings:(id)arg1 strength:(double)arg2 ;
@end

@interface SBUICallToActionLabel 
-(NSString *)text;
-(SBUILegibilityLabel *)label;
-(void)setLabel:(SBUILegibilityLabel *)textLabel;
-(void)setText:(NSString *)arg1 ;
@end