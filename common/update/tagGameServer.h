#ifndef TAGGAMESERVER_H
#define TAGGAMESERVER_H

#include "../Config.h"
#include "../../3rdParty/atom/atom/CAtom.h"
using namespace atom;

namespace version
{

    struct tagGameServer
    {
        // ����IP��ַ�Ͷ˿�
        tagDomain   domain;

        // ��������
        a_string    entity;

        // ������ɫ
        a_string    color;
        
        // ����
        a_string    flag_1;

        a_string    flag_2;
    };

    typedef std::vector<tagGameServer, atom_allocator<tagGameServer> >  GameServerList;
    typedef std::map<a_string, GameServerList, std::less<a_string>, 
        atom_allocator<std::pair<a_string, GameServerList> > >      GameServerArea;   

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
