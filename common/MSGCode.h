#ifndef CHGAME_MSGCode_H
#define CHGAME_MSGCode_H
#include "..\3rdparty\atom\electron\celectron.h"

//½âÂë
template <typename T>
inline CMessage& operator >> (CMessage& msg, T& value)
{
	U32 length=msg.ReadI32();
	CMemory data;
	if( data.Alloc(length) )
	{
		msg.ReadBytes( data, length );
		data.SetLength( length );
	}
	CArchive achieve;
	achieve.Assign(data);
	achieve>>value;
	return msg;
}

//±àÂë
template <typename T>
inline CMessage& operator << (CMessage& msg, T& value)
{
	CArchive archive;
	archive<<value;
	CMemory data;
	archive.Clone(data);
	msg.Write(data.GetLength());
	msg.Write(data,data.GetLength());
	return msg;
}

#endif