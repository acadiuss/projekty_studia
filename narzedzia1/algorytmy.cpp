<<<<<<< HEAD
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    // Inicjalizacja kamery
    VideoCapture cap(0);
    if(!cap.isOpened()){
        cerr << "Nie można otworzyć kamery." << endl;
        return -1;
    }

    // Określenie ścieżki folderu
    string folder_path = "ścieżka/do/folderu/z/zdjęciami/";

    // Pętla, która będzie działać dopóki program jest uruchomiony
    while(true)
    {
        // Przechwytywanie klatki z kamery
        Mat frame;
        cap >> frame;

        // Konwersja klatki do odcieni szarości
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Wykrywanie ruchu
        static Mat previous_gray;
        static Mat diff;
        static Mat binary;
        if(!previous_gray.empty()){
            absdiff(previous_gray, gray, diff);
            threshold(diff, binary, 50, 255, THRESH_BINARY);
            imshow("Ruch", binary);

            // Zapisywanie zdjęcia w folderze, jeśli wykryto ruch
            if(countNonZero(binary) > 0){
                string filename = folder_path + to_string(time(NULL)) + ".jpg";
                imwrite(filename, frame);
            }
        }
        previous_gray = gray;

        // Wyjście z pętli po naciśnięciu klawisza 'q'
        char key = waitKey(1);
        if(key == 'q'){
            break;
        }
    }

    // Zwolnienie zasobów kamery
    cap.release();
    destroyAllWindows();

    return 0;
}
=======
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv)
{
    // Inicjalizacja kamery
    VideoCapture cap(0);
    if(!cap.isOpened()){
        cerr << "Nie można otworzyć kamery." << endl;
        return -1;
    }

    // Określenie ścieżki folderu
    string folder_path = "ścieżka/do/folderu/z/zdjęciami/";

    // Pętla, która będzie działać dopóki program jest uruchomiony
    while(true)
    {
        // Przechwytywanie klatki z kamery
        Mat frame;
        cap >> frame;

        // Konwersja klatki do odcieni szarości
        Mat gray;
        cvtColor(frame, gray, COLOR_BGR2GRAY);

        // Wykrywanie ruchu
        static Mat previous_gray;
        static Mat diff;
        static Mat binary;
        if(!previous_gray.empty()){
            absdiff(previous_gray, gray, diff);
            threshold(diff, binary, 50, 255, THRESH_BINARY);
            imshow("Ruch", binary);

            // Zapisywanie zdjęcia w folderze, jeśli wykryto ruch
            if(countNonZero(binary) > 0){
                string filename = folder_path + to_string(time(NULL)) + ".jpg";
                imwrite(filename, frame);
            }
        }
        previous_gray = gray;

        // Wyjście z pętli po naciśnięciu klawisza 'q'
        char key = waitKey(1);
        if(key == 'q'){
            break;
        }
    }

    // Zwolnienie zasobów kamery
    cap.release();
    destroyAllWindows();

    return 0;
}
>>>>>>> 4c6f14fb57814dd263c909c7c1b8f8c5ea64219b
