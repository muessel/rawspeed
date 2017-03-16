/*
    RawSpeed - RAW file decoder.

    Copyright (C) 2013 Klaus Post
    Copyright (C) 2014 Pedro Côrte-Real

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
*/

#pragma once

#include "common/RawImage.h"              // for RawImage
#include "decoders/AbstractTiffDecoder.h" // for AbstractTiffDecoder
#include "tiff/TiffIFD.h"                 // for TiffRootIFDOwner
#include <algorithm>                      // for move

namespace RawSpeed {

class CameraMetaData;
class Buffer;

class RafDecoder final : public AbstractTiffDecoder
{
public:
  // please revert _this_ commit, once IWYU can handle inheriting constructors
  // using AbstractTiffDecoder::AbstractTiffDecoder;
  RafDecoder(TiffRootIFDOwner&& root, Buffer* file)
      : AbstractTiffDecoder(move(root), file) {}

  RawImage decodeRawInternal() override;
  void decodeMetaDataInternal(const CameraMetaData* meta) override;
  void checkSupportInternal(const CameraMetaData* meta) override;
  static bool isRAF(Buffer* input);

protected:
  int getDecoderVersion() const override { return 1; }
  void DecodeRaf();
  bool alt_layout = false;

private:
  int isCompressed();
};

} // namespace RawSpeed
