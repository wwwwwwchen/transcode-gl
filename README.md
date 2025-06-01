# Transcode-GL

A personal project to learn FFmpeg and OpenGL by building a transcoder and renderer for H.264/H.265 video.

## Features
- Transcode between H.264 and H.265 using FFmpeg
- Render and play video frames using OpenGL

## Project Milestones

| Date  | Milestone Description | Status |
|-------|------------------------|------|
| 6.3   | **File input and demuxing**: Retrieve and print stream info | Done |
| 6.6   | **Decode H.264/H.265 video streams**: Save decoded frame PTS info / resolution for later sync | In progress |
| 6.9   | **Encode raw video frames** to H.264 or H.265 and output as raw stream | Upcoming |
| 6.11  | **Extract audio stream** separately and sync A/V by aligning PTS during muxing | Upcoming |
| 6.13  | **Mux re-encoded video + original audio** into `.mp4` | Upcoming |
| 6.20  | **Learn OpenGL texture basics** and render decoded YUV frame (converted to RGB) | Upcoming |
| 7.2   | **Create render loop** using shader and VAO to display frames continuously | Upcoming |