#ifndef TIFF_ENTRY_BE_H
#define TIFF_ENTRY_BE_H

#include "TiffEntry.h"

/* 
    RawSpeed - RAW file decoder.

    Copyright (C) 2009-2014 Klaus Post

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

    http://www.klauspost.com
*/

namespace RawSpeed {

class TiffEntryBE :
  public TiffEntry
{
public:
//  TiffEntryBE(void);
  TiffEntryBE(FileMap* f, uint32 offset, uint32 up_offset);
  TiffEntryBE(TiffTag tag, TiffDataType type, uint32 count, const uchar8* data = NULL);
  virtual ~TiffEntryBE(void);
  virtual uint32 getInt(uint32 num=0);
  virtual int32 getSInt(uint32 num=0);
  virtual ushort16 getShort(uint32 num=0);
  virtual short16 getSShort(uint32 num=0);
  virtual float getFloat(uint32 num=0);
  virtual void setData(const void *in_data, uint32 byte_count );
};

} // namespace RawSpeed

#endif
