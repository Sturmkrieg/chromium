// Copyright (c) 2009 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// AudioRendererAlgorithmDefault is the default implementation of
// AudioRendererAlgorithmBase. For speeds other than 1.0f, Process() fills
// |buffer_out| with 0s and returns the expected size. As ARAB is
// thread-unsafe, so is ARAD.

#ifndef MEDIA_FILTERS_AUDIO_RENDERER_ALGORITHM_DEFAULT_H_
#define MEDIA_FILTERS_AUDIO_RENDERER_ALGORITHM_DEFAULT_H_

#include "base/time.h"
#include "media/base/data_buffer.h"
#include "media/filters/audio_renderer_algorithm_base.h"

namespace media {

class AudioRendererAlgorithmDefault : public AudioRendererAlgorithmBase {
 public:
  AudioRendererAlgorithmDefault();
  virtual ~AudioRendererAlgorithmDefault();

  // AudioRendererAlgorithmBase implementation
  virtual size_t Process(DataBuffer* buffer_out);

 private:
  // Remembers the amount of remaining audio data for the front buffer.
  size_t data_offset_;

  DISALLOW_COPY_AND_ASSIGN(AudioRendererAlgorithmDefault);
};

}  // namespace media

#endif  // MEDIA_FILTERS_AUDIO_RENDERER_ALGORITHM_DEFAULT_H_