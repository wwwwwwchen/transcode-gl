CXX = g++
CXXFLAGS = -std=c++17 -Wall

FFMPEG_FLAGS = `pkg-config --cflags --libs libavformat libavcodec libavutil`

SRCS = main.cpp demuxer/demux.cpp
TARGET = transcode-gl

all:
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(FFMPEG_FLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
