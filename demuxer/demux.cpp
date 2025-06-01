#include "demux.h"

extern "C" {
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
    #include <libavutil/avutil.h>
}

#include <iostream>

using namespace std;

AVFormatContext* Demuxer::open(const char* filename) {
    AVFormatContext *avfc = avformat_alloc_context();
    // Fail to allocate memory to AVFormatContext
    if (!avfc) {
        cerr << " LOG: Could not allocate memory for AVFormatContext" << endl;
        return NULL;
    }
    // Success
    if (avformat_open_input(&avfc, filename, NULL, NULL) == 0) {
        cout << " LOG: Successfully opened file: " << filename << endl;
        return avfc;
    } else {
        cerr << " LOG: Unable to open an input stream and read the header." << endl;
        return NULL;
    }
    return NULL;
}

void Demuxer::demux_print_info(AVFormatContext* avfc) {
    if (avformat_find_stream_info(avfc, NULL) < 0) {
        cerr << " LOG: Could not find stream information" << endl;
        return;
    }
    // Print container info
    cout << " Container info: " << endl;
    cout << "-------------------------" << endl;
    cout << " Start time: " << avfc->start_time / (double)AV_TIME_BASE << " s" << endl;
    cout << " Duration: " << avfc->duration / (double)AV_TIME_BASE << " s" << endl;
    cout << " Bit rate: " << avfc->bit_rate / 1000 << " kbps" << endl;
    cout << " Number of streams: " << avfc->nb_streams << endl << endl;
    cout << "-------------------------" << endl;
    cout << " Stream info: " << endl;
    cout << "-------------------------" << endl;
    
    // Print stream info
    for (unsigned int i = 0; i < avfc->nb_streams; i++) {
        cout << "Stream " << i+1 << " info:" << endl;
        AVStream* stream = avfc->streams[i];
        if (strcmp(av_get_media_type_string(stream->codecpar->codec_type), "video") == 0) {
            cout << " Stream type: " << av_get_media_type_string(stream->codecpar->codec_type) << endl;
            cout << " Stream Index: " << stream->index << endl;
            cout << " Stream ID: " << stream->id << endl;
            cout << " Number of frames(from container): " << stream->nb_frames << endl;
            cout << " Average frame rate: " << stream->avg_frame_rate.num / (double)stream->avg_frame_rate.den << " fps" << endl;
            cout << " Real frame rate: " << stream->r_frame_rate.num / (double)stream->r_frame_rate.den << " fps" << endl;
            cout << " Number of frames(estimate): " << stream->codec_info_nb_frames << endl;
            cout << " Resolution: " << stream->codecpar->width << "x" << stream->codecpar->height << " px" << endl;
            cout << " Codec type: " << avcodec_get_name(stream->codecpar->codec_id) << endl;
            cout << "-------------------------" << endl;
        } else if (strcmp(av_get_media_type_string(stream->codecpar->codec_type), "audio") == 0) {
            cout << " Stream type: " << av_get_media_type_string(stream->codecpar->codec_type) << endl;
            cout << " Stream Index: " << stream->index << endl;
            cout << " Stream ID: " << stream->id << endl;
            cout << " Number of frames(from container): " << stream->nb_frames << endl;
            cout << " Number of frames(estimate): " << stream->codec_info_nb_frames << endl;
            cout << " Sample rate: " << stream->codecpar->sample_rate << " Hz" << endl;
            cout << " Channels: " << stream->codecpar->channels << endl;
            cout << " Codec type: " << avcodec_get_name(stream->codecpar->codec_id) << endl;
            cout << "-------------------------" << endl;
        } else {
            continue;
        }
    }
}
