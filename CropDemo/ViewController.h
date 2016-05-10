//
//  ViewController.h
//  CropDemo
//
//  Created by Vrin-Ankit on 6/2/15.
//  Copyright (c) 2015 Vrinsoft. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MAImagePickerController.h"

@interface ViewController : UIViewController <MAImagePickerControllerDelegate>
{
    IBOutlet UIImageView *imgViewForCroppedImage;
}

@property (nonatomic, retain) UIImage *imgCropImage;

- (IBAction)initButton:(id)sender;

@end
