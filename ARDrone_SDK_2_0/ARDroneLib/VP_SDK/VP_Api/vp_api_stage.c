/**
 *  \brief    VP Api. Stages declaration.
 *  \author   Sylvain Gaeremynck <sylvain.gaeremynck@parrot.fr>
 *  \author   Aurelien Morelle <aurelien.morelle@parrot.fr>
 *  \author   Thomas Landais <thomas.landais@parrot.fr>
 *  \version  2.0
 *  \date     first release 16/03/2007
 *  \date     modification  19/03/2007
 */

///////////////////////////////////////////////
// INCLUDES

#include <VP_Api/vp_api_stage.h>
#include <VP_Api/vp_api_error.h>
#include <VP_Stages/vp_stages_io_file.h>
#include <VP_Stages/vp_stages_io_buffer.h>
#include <VP_Stages/vp_stages_io_com.h>
#include <VP_Stages/vp_stages_io_console.h>
#include <VP_Stages/vp_stages_yuv2rgb.h>
#include <VP_Stages/vp_stages_buffer_to_picture.h>
#include <VP_Stages/vp_stages_frame_pipe.h>

#ifdef _WIN32
#define SUCCESS 0
#endif
///////////////////////////////////////////////
// USEFULL FUNCTIONS

/*
 * "transparent" transform function
 */
C_RESULT
vp_api_stage_empty_transform (void *cfg, struct _vp_api_io_data_ *in, struct _vp_api_io_data_ *out)
{
  vp_os_mutex_lock(&out->lock);
  out->status = in->status;
  out->size = in->size;
  vp_os_mutex_unlock( &out->lock );

  return SUCCESS;
}


///////////////////////////////////////////////
// POINTERS

const vp_api_stage_funcs_t vp_stages_input_file_funcs =
{
  (vp_api_stage_handle_msg_t) NULL,
  (vp_api_stage_open_t) vp_stages_input_file_stage_open,
  (vp_api_stage_transform_t) vp_stages_input_file_stage_transform,
  (vp_api_stage_close_t) vp_stages_input_file_stage_close
};

const vp_api_stage_funcs_t vp_stages_output_file_funcs =
{
  (vp_api_stage_handle_msg_t) NULL,
  (vp_api_stage_open_t) vp_stages_output_file_stage_open,
  (vp_api_stage_transform_t) vp_stages_output_file_stage_transform,
  (vp_api_stage_close_t) vp_stages_output_file_stage_close
};

const vp_api_stage_funcs_t vp_stages_input_buffer_funcs =
{
  (vp_api_stage_handle_msg_t) NULL,
  (vp_api_stage_open_t) vp_stages_input_buffer_stage_open,
  (vp_api_stage_transform_t) vp_stages_input_buffer_stage_transform,
  (vp_api_stage_close_t) vp_stages_input_buffer_stage_close
};

const vp_api_stage_funcs_t vp_stages_output_buffer_funcs =
{
  (vp_api_stage_handle_msg_t) NULL,
  (vp_api_stage_open_t) vp_stages_output_buffer_stage_open,
  (vp_api_stage_transform_t) vp_stages_output_buffer_stage_transform,
  (vp_api_stage_close_t) vp_stages_output_buffer_stage_close
};

const vp_api_stage_funcs_t vp_stages_frame_pipe_sender_funcs =
{
  NULL,
  (vp_api_stage_open_t) vp_stages_frame_pipe_sender_open,
  (vp_api_stage_transform_t) vp_stages_frame_pipe_sender_transform,
  (vp_api_stage_close_t) vp_stages_frame_pipe_sender_close
};

const vp_api_stage_funcs_t vp_stages_frame_pipe_receiver_funcs =
{
  NULL,
  (vp_api_stage_open_t) vp_stages_frame_pipe_receiver_open,
  (vp_api_stage_transform_t) vp_stages_frame_pipe_receiver_transform,
  (vp_api_stage_close_t) vp_stages_frame_pipe_receiver_close
};

const vp_api_stage_funcs_t vp_stages_frame_pipe_fetch_funcs =
{
  NULL,
  (vp_api_stage_open_t) vp_stages_frame_pipe_fetch_open,
  (vp_api_stage_transform_t) vp_stages_frame_pipe_fetch_transform,
  (vp_api_stage_close_t) vp_stages_frame_pipe_fetch_close
};

const vp_api_stage_funcs_t vp_stages_buffer_to_picture_funcs =
{
  NULL,
  (vp_api_stage_open_t) vp_stages_buffer_to_picture_open,
  (vp_api_stage_transform_t) vp_stages_buffer_to_picture_transform,
  (vp_api_stage_close_t) vp_stages_buffer_to_picture_close
};


const vp_api_stage_funcs_t vp_stages_picture_to_buffer_funcs =
{
  NULL,
  (vp_api_stage_open_t) vp_stages_picture_to_buffer_open,
  (vp_api_stage_transform_t) vp_stages_picture_to_buffer_transform,
  (vp_api_stage_close_t) vp_stages_picture_to_buffer_close
};

const vp_api_stage_funcs_t vp_stages_input_com_funcs =
{
  (vp_api_stage_handle_msg_t) NULL,
  (vp_api_stage_open_t) vp_stages_input_com_stage_open,
  (vp_api_stage_transform_t) vp_stages_input_com_stage_transform,
  (vp_api_stage_close_t) vp_stages_input_com_stage_close
};

const vp_api_stage_funcs_t vp_stages_output_com_funcs =
{
  (vp_api_stage_handle_msg_t) NULL,
  (vp_api_stage_open_t) vp_stages_output_com_stage_open,
  (vp_api_stage_transform_t) vp_stages_output_com_stage_transform,
  (vp_api_stage_close_t) vp_stages_output_com_stage_close
};

const vp_api_stage_funcs_t vp_stages_output_console_funcs =
{
  (vp_api_stage_handle_msg_t) NULL,
  (vp_api_stage_open_t) vp_stages_output_console_stage_open,
  (vp_api_stage_transform_t) vp_stages_output_console_stage_transform,
  (vp_api_stage_close_t) vp_stages_output_console_stage_close
};

const vp_api_stage_funcs_t vp_stages_yuv2rgb_funcs =
{
  (vp_api_stage_handle_msg_t) NULL,
  (vp_api_stage_open_t) vp_stages_yuv2rgb_stage_open,
  (vp_api_stage_transform_t) vp_stages_yuv2rgb_stage_transform,
  (vp_api_stage_close_t) vp_stages_yuv2rgb_stage_close
};

