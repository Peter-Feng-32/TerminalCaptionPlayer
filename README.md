# TerminalCaptionPlayer

Terminal app that reads JSON files and plays them as captions.

Note: If termux keyboard disappears, just tap on the screen once.

Create CaptionPlayer folder with build folder, play_captions.cpp, CMakeLists.txt, and merged_captions.1.json in build folder.
Drag CaptionPlayer folder into Android Downloads using a file manager like OpenMTP.
In Termux, go to storage, move to $PREFIX
Inside $PREFIX/CaptionPlayer/build run:

cmake ../CMakeLists.txt
make all
./CaptionPlayer
