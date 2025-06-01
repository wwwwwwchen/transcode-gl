#include "demuxer/demux.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "Invalid number of parameter" << endl;
    }

    const char* file = argv[1];
    Demuxer demux;
    AVFormatContext* avfc = demux.open(file);
    demux.demux_print_info(avfc);
    avformat_close_input(&avfc);

    return 0;
}

