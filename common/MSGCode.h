#ifndef CHGAME_MSGCode_H
#define CHGAME_MSGCode_H

#include "../3rdParty/atom/electron/CElectron.h"
using namespace electron;

//从message解码
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
	data>>value;
	return msg;
}

//从message编码
template <typename T>
inline CMessage& operator << (CMessage& msg, T& value)
{
	CMemory data;
	data<<value;
	msg.Write(data.GetLength());
	msg.Write(data,data.GetLength());
	return msg;
}

//从memory解码
template <typename T>
inline CMemory& operator >> (CMemory& data, T& value)
{
	CArchive achieve;
	achieve.Assign(data);
	achieve>>value;
	return data;
}

//从memory编码
template <typename T>
inline CMemory& operator << (CMemory& data, T& value)
{
	CArchive archive;
	archive<<value;
	archive.Clone(data);
	return data;
}

#endif