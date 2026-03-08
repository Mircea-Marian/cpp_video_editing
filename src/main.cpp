// Modify bellow if you want other behavior of the app before compiling.
#define WIDTH 1280
#define HEIGHT 720
#define INVERT_COLORS
#define FLIP
#define OUTPUT_FILE_PATH "output_video.mp4"

#include <opencv2/opencv.hpp>
#include <iostream>

int main() {

    // Construct the capture object that will get the video stream from the laptop camera.
    cv::VideoCapture cap(0);

    // Check if the camera could be opened.
    if (!cap.isOpened()) {
        std::cerr << "Error: Could not open camera !\n";
        return -1;
    }

    // Get the fps of the capture so the video writer knows what fps to use.
    double fps = cap.get(cv::CAP_PROP_FPS);
    if (fps == 0)
        fps = 30;

    // Set up the writer object with the desired format, size and fps
    cv::VideoWriter writer(
        OUTPUT_FILE_PATH,
        cv::VideoWriter::fourcc('a','v','c','1'),
        fps,
        cv::Size(WIDTH, HEIGHT)
    );

    // Check if the writer could be opened.
    if (!writer.isOpened()) {
        std::cerr << "Error: Could not open writer !\n";
        return -1;
    }

    cv::Mat frame0, frame1;

    while (true) {

        cap >> frame0;

        // Check if stream is working
        if (frame0.empty())
            break;

        cv::resize(frame0, frame1, cv::Size(WIDTH, HEIGHT));
        frame0 = frame1;

#ifdef INVERT_COLORS
        cv::bitwise_not(frame0, frame1);
        frame0 = frame1;
#endif

#ifdef FLIP
        cv::flip(frame0, frame1, 1);
        frame0 = frame1;
#endif

        // encode to H264
        writer.write(frame0);

        // display
        cv::imshow("Processed Video Stream", frame0);

        if (cv::waitKey(1) == 27)
            break;
    }

    cap.release();
    writer.release();
    cv::destroyAllWindows();

    return 0;
}