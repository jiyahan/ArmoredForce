#ifndef CATOM_H
#define CATOM_H
#include "Common.h"

// 系统相关
#include "os/thread/CCriticalSection.h"
#include "os/thread/CSignal.h"
#include "os/thread/CThread.h"
#include "os/thread/CReference.h"
#include "os/timer/CMilisecondTimer.h"
#include "os/timer/CSystemTimer.h"
#include "os/memory/CMemoryScheduler.h"
#include "os/memory/CMemory.h"
#include "os/character/CCharacter.h"
#include "os/character/CCodePage.h"
#include "os/library/CLibrary.h"
#include "os/path/CPath.h"
#include "os/file/CFile.h"
#include "os/directory/CDirectory.h"
#include "os/net/CTcpConnector.h"
#include "os/net/CTcpListener.h"
#include "os/net/CTcpSelectModel.h"
#include "os/net/CTcpIocpModel.h"
#include "os/net/CTcpKQueueModel.h"
#include "os/net/CTcpEpollModel.h"
#include "os/net/CTcpNetworkService.h"
#include "os/net/tagDomain.h"
#include "os/net/utility/CSocketUtility.h"
#include "os/system/CSystemInformation.h"
#include "os/callstack/CCallStack.h"

#include "pattern/singleton/CSingleton.h"
#include "pattern/container/CInstanceAliasContainer.h"
#include "pattern/container/CInstanceContainer.h"
#include "pattern/allocator/CAtomAllocator.h"
#include "pattern/factory/CInstanceFactory.h"
#include "pattern/life/CInstanceLife.h"
#include "pattern/object/CReferencedObject.h"
#include "pattern/event/CEventService.h"
#include "pattern/event/CEventSpace.h"
#include "pattern/event/CEventEmitter.h"
#include "pattern/event/CEventDirectEmitter.h"
#include "pattern/event/tagEvent.h"
#include "maintainer/CMaintainer.h"

#include "stream/wrapper/CAssignableWrapper.h"
#include "stream/wrapper/CClonableWrapper.h"
#include "stream/wrapper/CClosableWrapper.h"
#include "stream/wrapper/CExportableWrapper.h"
#include "stream/wrapper/CFlushableWrapper.h"
#include "stream/wrapper/CImportableWrapper.h"
#include "stream/wrapper/CSwappableWrapper.h"
#include "stream/wrapper/CTruncatableWrapper.h"
#include "stream/reader/CDataReader.h"
#include "stream/writer/CDataWriter.h"
#include "stream/memory/CImportStream.h"
#include "stream/memory/CExportStream.h"
#include "stream/object/CImporter.h"
#include "stream/object/CExporter.h"
#include "stream/object/CIOPorter.h"

#include "serialization/extend/stl.h"
#include "serialization/extend/atom.h"
#include "serialization/tagSerializer.h"
#include "serialization/CArchive.h"

#include "log/CLogService.h"
#include "log/CLog.h"

#include "utility/math/random/CRandom.h"
#include "utility/member/CMembers.h"
#include "utility/cache/CObjectCache.h"
#include "utility/stl/stl_extend.h"
#include "utility/stl/allocator.h"
#include "utility/stl/a_string.h"
#include "utility/stl/a_wstring.h"
#include "utility/stl/CStringArray.h"
#include "utility/stl/CWStringArray.h"
#include "utility/stl/CU08Array.h"
#include "utility/stl/CU16Array.h"
#include "utility/stl/CU32Array.h"
#include "utility/stl/CU64Array.h"
#include "utility/stl/CI08Array.h"
#include "utility/stl/CI16Array.h"
#include "utility/stl/CI32Array.h"
#include "utility/stl/CI64Array.h"
#include "utility/byteswap/CByteSwap.h"
#include "utility/timeline/CTimeLine.h"
#include "utility/tool/CCriticalSectionScope.h"
#include "utility/tool/CInterface.h"
#include "utility/tool/CObjectPtr.h"
#include "utility/tool/CInstanceUtility.h"
#include "utility/indices/CIndices.h"
#include "utility/indices/CIndicesX.h"
#include "utility/variant/CVariant.h"
#include "utility/variant/CVariantArray.h"
#include "utility/variant/CVariants.h"
#include "utility/charset/CUtf8Charset.h"
#include "utility/checksum/alogrithm/internet/internet.h"
#include "utility/base64/CBase64Codec.h"
#include "utility/allocator/CAllocator.h"
#include "utility/xml/CXmlDocument.h"
#include "utility/xml/CXmlElement.h"
#include "utility/xml/CXmlDocumentPtr.h"
#include "utility/xml/CXmlElementPtr.h"

#include "interface/IAssignable.h"
#include "interface/IClonable.h"
#include "interface/IClosable.h"
#include "interface/IEmbedInterface.h"
#include "interface/IEventEmitter.h"
#include "interface/IEventReceiver.h"
#include "interface/IEventServiceEntry.h"
#include "interface/IEventServiceTimeline.h"
#include "interface/IEventSpaceController.h"
#include "interface/IExportable.h"
#include "interface/IExportStream.h"
#include "interface/IFileStream.h"
#include "interface/IFlushable.h"
#include "interface/IFlushDevice.h"
#include "interface/IImportable.h"
#include "interface/IImportStream.h"
#include "interface/IInstanceAliasContainer.h"
#include "interface/IInstanceAllocator.h"
#include "interface/IInstanceContainer.h"
#include "interface/IInstanceContainerListener.h"
#include "interface/IInstanceFactoryAllocator.h"
#include "interface/IInstanceFactoryEntry.h"
#include "interface/IInstanceLife.h"
#include "interface/IInstanceLifeController.h"
#include "interface/IInstanceLifeNotify.h"
#include "interface/IInstanceLifeNotifyReceiver.h"
#include "interface/IInstanceLifeReference.h"
#include "interface/IInterface.h"
#include "interface/ILogArchive.h"
#include "interface/ILogServiceController.h"
#include "interface/IMaintainable.h"
#include "interface/IMaintainerTimeline.h"
#include "interface/IMultiThreadControl.h"
#include "interface/IReferencedInterface.h"
#include "interface/IReferencedObject.h"
#include "interface/IStream.h"
#include "interface/ISwappable.h"
#include "interface/ITcpConnectionController.h"
#include "interface/ITcpConnectorController.h"
#include "interface/ITcpConnectorFlushDevice.h"
#include "interface/ITcpEpollIOModel.h"
#include "interface/ITcpIocpIOModel.h"
#include "interface/ITcpIOModel.h"
#include "interface/ITcpKQueueIOModel.h"
#include "interface/ITcpListenerController.h"
#include "interface/ITcpNetworkServiceController.h"
#include "interface/ITcpSelectIOModel.h"
#include "interface/IThreadControl.h"
#include "interface/ITruncatable.h"
#include "interface/IXmlDocumentNode.h"
#include "interface/IXmlElementNode.h"

#include "enumeration/END_ALARM.h"
#include "enumeration/END_DEBUG.h"
#include "enumeration/END_ERROR.h"
#include "enumeration/INTERFACE_ID.h"
#include "enumeration/LINE_END.h"
#include "enumeration/LOG_LEVEL.h"
#include "enumeration/OBJECT_ID.h"
#include "enumeration/SINGLETON_OBJECT_ID.h"
#include "enumeration/THREAD_PRIORITY.h"
#include "enumeration/EVENT_ID.h"
#include "enumeration/VARIANT_TYPE.h"



namespace atom
{



    class CAtom
    {


        private:


            static bool active;




        public:

            static void Presetup(); 

			
			
            static bool Initiate(size_t memory_pool); 



            static bool Shutdown(); 



            static void Destruct(); 

			
			
            static bool IsActive(); 



    };  //end class CAtom


}//end namespace atom


#endif
