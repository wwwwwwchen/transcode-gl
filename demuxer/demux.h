#pragma once

extern "C" {
    #include <libavformat/avformat.h>
}

class Demuxer {
public:

    /**
     * Open a media file and return its AV format context.
     * 
     * @param filename The path to the input media file.
     * @return AVFormatContext* pointer to the AV format context of the input file. Return NULL if fail.
     */
    AVFormatContext* open(const char* filename);

    /**
     * Print information of container and each stream from the given AV format context.
     * 
     * @param avfc The pointer to the AV format context of the input file.
     */
    void demux_print_info(AVFormatContext* avfc);
};