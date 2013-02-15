//
//  PBListViewConfig.h
//  PBListView
//
//  Created by Nick Bolton on 2/9/13.
//  Copyright 2013 Pixelbleed. All rights reserved.
//

typedef NS_ENUM(NSInteger, PBListViewPositionType) {

    PBListViewPositionTypeFirst = 0,
    PBListViewPositionTypeMiddle,
    PBListViewPositionTypeLast,
    PBListViewPositionTypeOnly,
    PBListViewPositionTypeCount, // used internally
};

typedef NS_ENUM(NSInteger, PBListViewUIElementType) {

    PBListViewUIElementTypeText = 0,
    PBListViewUIElementTypeButton,
    PBListViewUIElementTypeImage,
};

@class PBListViewUIElementMeta;
@class PBMenu;

@interface PBListViewConfig : NSObject

@property (nonatomic) CGFloat leftMargin;
@property (nonatomic) CGFloat rightMargin;
@property (nonatomic) NSSize minSize;
@property (nonatomic) NSSize maxSize;
@property (nonatomic, strong) NSColor *rowDividerLineColor;
@property (nonatomic) CGFloat rowDividerLineHeight;
@property (nonatomic, strong) NSColor *selectedBackgroundColor;
@property (nonatomic, strong) NSColor *selectedBorderColor;
@property (nonatomic) CGFloat selectedBorderRadius;
@property (nonatomic) BOOL autoBuildContextualMenu;

- (void)registerUIElementMeta:(PBListViewUIElementMeta *)meta;
- (NSArray *)metaListForEntityType:(Class)entityType
                           atDepth:(NSUInteger)depth;

- (void)registerDefaultBackgroundImage:(NSImage *)defaultBackgroundImage
        defaultHoveringBackgroundImage:(NSImage *)defaultHoveringBackgroundImage
               selectedBackgroundImage:(NSImage *)selectedBackgroundImage
       selectedHoveringBackgroundImage:(NSImage *)selectedHoveringBackgroundImage
               expandedBackgroundImage:(NSImage *)expandedBackgroundImage
       expandedHoveringBackgroundImage:(NSImage *)expandedHoveringBackgroundImage
                  forEntityType:(Class)entityType
                     atPosition:(PBListViewPositionType)positionType;
- (void)registerDefaultBackgroundImage:(NSImage *)defaultBackgroundImage
        defaultHoveringBackgroundImage:(NSImage *)defaultHoveringBackgroundImage
               selectedBackgroundImage:(NSImage *)selectedBackgroundImage
       selectedHoveringBackgroundImage:(NSImage *)selectedHoveringBackgroundImage
               expandedBackgroundImage:(NSImage *)expandedBackgroundImage
       expandedHoveringBackgroundImage:(NSImage *)expandedHoveringBackgroundImage
                         forEntityType:(Class)entityType
                        atDepth:(NSUInteger)depth
                     atPosition:(PBListViewPositionType)positionType;
- (void)registerBackgroundImage:(NSImage *)backgroundImage
                  forEntityType:(Class)entityType
                        atDepth:(NSUInteger)depth
                     atPosition:(PBListViewPositionType)positionType
                       selected:(BOOL)selected
                       hovering:(BOOL)hovering
                       expanded:(BOOL)expanded;

- (NSImage *)backgroundImageForEntityType:(Class)entityType
                                  atDepth:(NSUInteger)depth
                               atPosition:(PBListViewPositionType)positionType
                                 selected:(BOOL)selected
                                 hovering:(BOOL)hovering
                                 expanded:(BOOL)expanded;

- (void)registerRowHeight:(CGFloat)rowHeight
            forEntityType:(Class)entityType
                  atDepth:(NSUInteger)depth;
- (CGFloat)rowHeightForEntityType:(Class)entityType atDepth:(NSUInteger)depth;

- (PBMenu *)contextMenuForEntityType:(Class)entityType atDepth:(NSUInteger)depth;
- (void)registerContextMenu:(PBMenu *)menu
              forEntityType:(Class)entityType
                    atDepth:(NSUInteger)depth;
- (void)registerContextMenuSeparatorPositions:(NSIndexSet *)indexSet
                            forEntityType:(Class)entityType;
- (void)registerContextMenuSeparatorPositions:(NSIndexSet *)indexSet
           forEntityType:(Class)entityType
                 atDepth:(NSUInteger)depth;
- (void)registerCommands:(NSArray *)commands
           forEntityType:(Class)entityType;
- (void)registerCommands:(NSArray *)commands
           forEntityType:(Class)entityType
                 atDepth:(NSUInteger)depth;
- (NSArray *)commandsForEntityType:(Class)entityType
                           atDepth:(NSUInteger)depth;

@end
