#ifndef ITCPSELECTIOMODEL_H
#define ITCPSELECTIOMODEL_H
#include "ITcpIOModel.h"



namespace atom
{


	
	class ITcpSelectIOModel : public ITcpIOModel
	{




		public:

			virtual void SetActive(bool value) = 0; 



			virtual I32 OnProcess() = 0; 



	};  //end class ITcpSelectIOModel



} //end namespace



#endif
