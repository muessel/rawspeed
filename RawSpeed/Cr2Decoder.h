/* 
    RawSpeed - RAW file decoder.

    Copyright (C) 2009 Klaus Post

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
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301  USA

    http://www.klauspost.com
*/
#pragma once
#include "RawDecoder.h"
#include "LJpegPlain.h"
#include "TiffIFD.h"

class Cr2Decoder :
  public RawDecoder
{
public:
  Cr2Decoder(TiffIFD *rootIFD, FileMap* file);
  virtual RawImage decodeRaw();
  virtual void checkSupport(CameraMetaData *meta);
  virtual void decodeMetaData(CameraMetaData *meta);
  virtual ~Cr2Decoder(void);
protected:
  TiffIFD *mRootIFD;
};

class Cr2Slice {
public:
  Cr2Slice() { w = h = offset = count = 0;};
  ~Cr2Slice() {};
  guint w;
  guint h;
  guint offset;
  guint count;
};