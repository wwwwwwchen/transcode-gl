#include <libavformat/avformat.h>
#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

class Demuxer {
public:
    bool open(const char* filename);
    void print_info(AVFormatContext* avfc);
};

bool Demuxer::open(const char* filename) {
    AVFormatContext *avfc = avformat_alloc_context();
    if (!avfc) {
        cerr << " LOG: Could not allocate memory for AVFormatContext" << endl;
        return false;
    }
    if (avformat_open_input(&avfc, filename, NULL, NULL) == 0) {
        cout << " LOG: Successfully opened file: " << filename << endl;
    }
}

void print_info(AVFormatContext* avfc) {
    avformat_find_stream_info(avfc, NULL);
    cout << " Start time: " << avfc->start_time << endl;
    cout << " Duration: " << avfc->duration << endl;
    cout << " Bit rate: " << avfc->bit_rate << endl;
    cout << " Number of streams: " << avfc->nb_streams << endl;
    for (int i = 0; i < avfc->nb_streams; i++) {
        cout << "Stream " << i+1 << " info:" << endl;
        AVStream* stream = avfc->streams[i];
        cout << " Stream Index: " << stream->index << endl;
        cout << " Stream ID: " << stream->id << endl;
        cout << " Number of frames: " << stream->nb_frames << endl;
    }
}