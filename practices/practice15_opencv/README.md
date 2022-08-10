## The opencv version I used is 4.6.0

If you want to have a build like I do, follow the instructions below:

Go to this link
```
https://github.com/opencv/opencv/releases/tag/4.6.0
```
Click ```opencv-4.6.0-vc14_vc15.exe```

Then download opencv.

I use Windows11, so I added ```your drive here:\opencv\build\x64\vc15\bin``` to my User Envirment Variables Path.

I use Vistual Studio 2022, so an empty project. In the project properties, go to "VC++ Directories", and then <\br>
add ```your drive here:\opencv\build\include``` in General->Include Directories; <\br>
add ```your drive here:\opencv\build\x64\vc15\lib``` in General->Lirary Directories. <\br>

After this, go to the "Linker". 
add ```opencv_world460d.lib``` in Additional Dependencies.

Click apply. 

Done.


