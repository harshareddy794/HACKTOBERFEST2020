# Motion Detection in Python
## By Harshal S Zodape

## Introduction
For detecting motion, we will use the Open-CV module. We start with a baseline_image, which is the frame captured without any moving object inside it. As soon as the camera fires, the first image is set to our baseline_image, which means that we expect no moving object when our program first starts. Next, when somebody enters the frame, certain pixels in that frame will be different. We deduce this difference using the “cv2.absdiff” method.
There are a few steps we will take to achieve this.
1. Capture the baseline_frame (with no object)
1.1 Convert the frame to Gray
1.2 Smoothen the frame to remove noise
2. Capture the new_frame (with object)
2.1 Convert the frame to Gray
2.2 Smoothen the frame to remove noise
3. Calculate the difference between the two frames
3.1 If difference is greater than the threshold, assume motion is detected
3.2 Else assume no motion detected

## Requirement:
1. Python3
2. OpenCV(libraries)
3. Pandas(libraries)

## Main Logic : 
Videos can be treated as stack of pictures called frames. Here I am comparing different frames(pictures) 
to the first frame which should be static(No movements initially). 
We compare two images by comparing the intensity value of each pixels. In python we can do 
it easily as you can see Dectecton.py file.

## For more Infomation:

[Link1](https://www.geeksforgeeks.org/webcam-motion-detector-python/)
[Link2](https://towardsdatascience.com/build-a-motion-triggered-alarm-in-5-minutes-342fbe3d5396)
[Youtubelink1](https://www.youtube.com/watch?v=-RUu3EcielI)
[Youtubelink2](https://www.youtube.com/watch?v=sRIdyfh3054)
