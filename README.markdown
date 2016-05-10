# WARNING - CONSIDER THIS CODEBASE DEPRECATED. TAKE A LOOK AT: [IPDFCameraViewController](https://github.com/mmackh/IPDFCameraViewController)

## MAImagePickerController aka. InstaOverlay

MAImagePickerController is a critical component of the InstaPDF (http://instapdf.me) for iPhone app. I've started to code in Objective C a couple of months ago, so please
offer your insights into making the component better.

Credits:
- Jayesh Mardiya

Be sure to checkout the ToDo!

## ToDo

1. ~~Improve Paper (Edge) Detection~~
2. Fix rotation of UIImages chosen from the Library
3. Store the rotations in the final view
4. ~~Improve API~~


## Screenshots

![Camera Viewer](https://github.com/mmackh/MAImagePickerController-of-InstaPDF/blob/master/screen1.PNG?raw=true "Take an image")

![Cropping View](https://github.com/mmackh/MAImagePickerController-of-InstaPDF/blob/master/screen2.PNG?raw=true "Crop")

![Final/Adjusting View](https://github.com/mmackh/MAImagePickerController-of-InstaPDF/blob/master/screen3.PNG?raw=true "Adjust the image, rotate, filter and confirm.")

## Using it in your project

1. Add all the necessary files inside MAImagePicker to your Project
2. #import "MAImagePickerController.h" in your ViewController's header (.h) file & declare that it can be delegated by MAImagePickerControllerDelegate
3. IMPORTANT: This project uses the OpenCV framework. Download the newest version here: 'http://opencv.org/'
4. Double check all the necessary frameworks: 'CoreImage.framework', 'opencv2.framework', 'QuartzCore.framework', 'ImageIO.framework', 'CoreMedia.framework', 'AVFoundation.framework', MediaPlayer.framework
5. The API is rather simple, use it like this:

```objective-c
- (IBAction)initButton:(id)sender
{
    MAImagePickerController *imagePicker = [[MAImagePickerController alloc] init];
   
    [imagePicker setDelegate:self];
    [imagePicker setSourceType:MAImagePickerControllerSourceTypeCamera];
    
    UINavigationController *navigationController = [[UINavigationController alloc] initWithRootViewController:imagePicker];
    
    [self presentViewController:navigationController animated:YES completion:nil];
}

- (void)imagePickerDidCancel
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)imagePickerDidChooseImageWithPath:(NSString *)path
{
    [self dismissViewControllerAnimated:YES completion:nil];
    
    if ([[NSFileManager defaultManager] fileExistsAtPath:path])
    {
        NSLog(@"File Found at %@", path);
        
    }
    else
    {
        NSLog(@"No File Found at %@", path);
    }
    
    [[NSFileManager defaultManager] removeItemAtPath:path error:nil];
}
```