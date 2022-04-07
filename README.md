# TerminalCaptionPlayer

Terminal app that reads JSON files and plays them as captions.

Note: If termux keyboard disappears, just tap on the screen once.

Drag TerminalCaptionPlayer folder into Android Downloads using a file manager like OpenMTP.
In Termux, go to storage, move to $PREFIX:
cd storage
cd downloads
mv TerminalCaptionPlayer $PREFIX
cd $PREFIX
cd build
rm CMakeCache.txt

cmake ../CMakeLists.txt
make all
./CaptionPlayer

For CaptionPlayer, enter 1-4 to play different captions.
