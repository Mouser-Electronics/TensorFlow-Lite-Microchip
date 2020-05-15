/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include "tensorflow/lite/micro/examples/person_detection/image_provider.h"

#include "tensorflow/lite/micro/examples/person_detection/model_settings.h"

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

uint32_t frame_buf[CONF_PCC_DMA_FRAME_SIZE];

static void capture_cb(struct camera_async_descriptor *const descr, uint32_t ch)
{
	if (ch == 0) {
		// Application can process data in frame_buf.
		camera_async_capture_start(&CAMERA_0, 0, frame_buf);
	}
}


TfLiteStatus GetImage(tflite::ErrorReporter* error_reporter, int image_width,
                      int image_height, int channels, uint8_t* image_data) {

  camera_async_register_callback(&CAMERA_0, capture_cb);
	camera_async_enable(&CAMERA_0);
	camera_async_capture_start(&CAMERA_0, 0, frame_buf);                      

  for (int i = 0; i < image_width * image_height * channels; ++i) {
    image_data[i] = frame_buf[i];
  }
  return kTfLiteOk;
}
