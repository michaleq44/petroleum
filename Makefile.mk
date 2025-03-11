SRC_DIR = $(shell pwd)
PROJECT_VERSION = 1.0.0

debug:
	rm -rf build/debug
	mkdir -p build/debug/bin
	g++ -c src/main.cpp -o build/debug/bin/main.o -Iinc -std=c++20
	g++ -c src/util.cpp -o build/debug/bin/util.o -Iinc -std=c++20
	g++ -c src/window.cpp -o build/debug/bin/window.o -Iinc -std=c++20
	windres src/res.rc -o build/debug/bin/res.o -Iinc
	g++ build/debug/bin/main.o build/debug/bin/util.o build/debug/bin/window.o build/debug/bin/res.o -o build/debug/bin/gamelaunch.exe -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lcomctl32 -std=c++20
	rm -rf build/debug/*.o
	cd build/debug/bin ; ./gamelaunch

_r:
	rm -rf build/release
	mkdir -p build/release/bin
	g++ -c src/main.cpp -o build/release/bin/main.o -Iinc -std=c++20
	g++ -c src/util.cpp -o build/release/bin/util.o -Iinc -std=c++20
	g++ -c src/window.cpp -o build/release/bin/window.o -Iinc -std=c++20
	windres src/res.rc -o build/release/bin/res.o -Iinc
	g++ build/release/bin/main.o build/release/bin/util.o build/release/bin/window.o build/release/bin/res.o -o build/release/bin/gamelaunch.exe -lkernel32 -luser32 -lgdi32 -lcomdlg32 -lcomctl32 -mwindows -std=c++20
	rm -rf build/release/*.o

release: _r
	cd build/release/bin ; ./gamelaunch