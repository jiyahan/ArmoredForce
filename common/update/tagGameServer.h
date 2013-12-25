#ifndef TAGGAMESERVER_H
#define TAGGAMESERVER_H

#include "Config.h"
#include "../../3rdParty/atom/atom/CAtom.h"
using namespace atom;

namespace version
{

    struct tagGameServer
    {
        // 区服IP地址和端口
        tagDomain   domain;

        // 区服名称
        String    entity;

        // 区服颜色
        String    color;
        
        // 保留
        String    flag_1;

        String    flag_2;
    };

#ifdef  NOT_USE_ATOM_ALLOCATOR  
    typedef std::vector<tagGameServer>          GameServerList;
    typedef std::map<String, GameServerList>    GameServerArea;
#else
    typedef std::vector<tagGameServer, atom_allocator<tagGameServer> >  GameServerList;
    typedef std::map<a_string, GameServerList, std::less<a_string>, 
        atom_allocator<std::pair<a_string, GameServerList> > >      GameServerArea;
#endif
    

} //end namespace version



template<class Archive>
inline void Serialize(Archive & archive, version::tagGameServer & value, bool isSave)
{
    UNREFERENCED_PARAMETER(isSave);
    archive.Bind( value.domain.host );
    archive.Bind( value.domain.port );
    archive.Bind( value.entity );
    archive.Bind( value.color );
    archive.Bind( value.flag_1 );
    archive.Bind( value.flag_2 );
}


#endif
