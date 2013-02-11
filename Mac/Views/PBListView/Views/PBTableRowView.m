//
//  PBTableRowView.m
//  PBListView
//
//  Created by Nick Bolton on 2/10/13.
//  Copyright (c) 2013 Pixelbleed. All rights reserved.
//

#import "PBTableRowView.h"
#import "PBListViewConfig.h"

@interface PBTableRowView() {

    NSTrackingRectTag trackingTag_;
}

@end

@implementation PBTableRowView

- (BOOL)mouseEnteredEventsStarted {
    return trackingTag_ != 0;
}

- (void)startMouseEnteredEvents {
    
//    CGFloat buffer = NSHeight(self.bounds) / 6.0f;
//    NSRect frame =
//    NSMakeRect(0,
//               buffer,
//               NSWidth(self.bounds),
//               NSHeight(self.bounds) - (2 * buffer));

    trackingTag_ =
    [self
     addTrackingRect:self.bounds
     owner:self
     userData:nil
     assumeInside:YES];
    
    [self.window setIgnoresMouseEvents:NO];
}

- (void)stopMouseEnteredEvents {
    [self removeTrackingRect:trackingTag_];
    trackingTag_ = 0;
}

- (void)mouseEntered:(NSEvent*)event {
    [_delegate rowViewSetHoverState:self];
}

- (void)mouseExited:(NSEvent *)event {
    [_delegate rowViewClearHoverState:self];
}

- (void)setSelected:(BOOL)selected {
    [super setSelected:selected];
}

- (void)drawRect:(NSRect)dirtyRect {

    if (self.selected) {

        if (_selectedBackgroundImage != nil) {

            NSSize size = _selectedBackgroundImage.size;

            [_selectedBackgroundImage
             drawInRect:dirtyRect
             fromRect:NSMakeRect(0.0f, 0.0f, size.width, size.height)
             operation:NSCompositeSourceOver
             fraction:1.0f];

        } else if (_selectedBackgroundColor != nil) {

            NSBezierPath *path =
            [NSBezierPath
             bezierPathWithRoundedRect:dirtyRect
             xRadius:_selectedBorderRadius
             yRadius:_selectedBorderRadius];

            [path addClip];

            [_selectedBackgroundColor set];
            [path fill];

            [_selectedBorderColor set];
            [path stroke];
        }
    } else {
        if (_backgroundImage != nil) {

            NSSize size = _backgroundImage.size;

            [_backgroundImage
             drawInRect:dirtyRect
             fromRect:NSMakeRect(0.0f, 0.0f, size.width, size.height)
             operation:NSCompositeSourceOver
             fraction:1.0f];

        }
    }

    [super drawRect:dirtyRect];
}
@end