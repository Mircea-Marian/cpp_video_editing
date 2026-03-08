# Real-Time Video Stream Processor

## Description

This application captures a video stream from the default camera,
performs real-time processing, encodes the stream to H264,
and displays the processed output.

---

## Dependencies

The project works on Windows.

Install "Developer PowerShell for VS 2022" or newer.

Download https://github.com/opencv/opencv/releases/download/4.12.0/opencv-4.12.0-windows.exe. On double-clicking, it will self-extract a folder "opencv".
Copy the "opencv" folder into the "lib" folder inside the project. Open the "folder_tree.png" file to check out how the intial folder structure should look like.

---

## Application Settings

At the begining of the src/main.cpp file, you will find some defines. Before compiling, you can customize the appliation to your liking.

---

## Build

An example for the bellow "your_global_path_to_opencv_build_folder" is "C:/Users/mircea/Desktop/coding_challange_/lib/opencv/build". Modify the command to your personal setup.

Open your "Developer PowerShell for VS 2022" console and go to the repository root. Input the following 3 commands:
--> cd build
--> cmake -DOpenCV_DIR="your_global_path_to_opencv_build_folder" ..
--> cmake --build . --config Release

---

## Run

Open the File Explorer application. Go into the folder of the repository. Navigate to build\Release. Double-click the "video_processor.exe" executable. To exit the program, press "Esc" key.