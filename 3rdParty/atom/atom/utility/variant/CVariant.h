#ifndef CVARIANT_H
#define CVARIANT_H
#include "tagVariant.h"
#include "../../os/memory/CMemory.h"



namespace atom
{



	class CVariant
	{


		public:

			enum STRING_TYPE
			{



					ST_TXT,


					ST_FLT,


					ST_INT

			}; //end enum STRING_TYPE 


		private:


			tagVariant variant;



			mutable CMemory convert;



			U08 Parse(const char * string); 



			U08 Parse(const wchar_t * string); 



		public:

			CVariant(); 



			CVariant(const CVariant & value); 



			CVariant(I08 value); 



			CVariant(I16 value); 



			CVariant(I32 value); 



			CVariant(I64 value); 



			CVariant(U08 value); 



			CVariant(U16 value); 



			CVariant(U32 value); 



			CVariant(U64 value); 



			CVariant(float value); 



			CVariant(double value); 



			CVariant(const char * value); 



			CVariant(const wchar_t * value); 



			CVariant(const CMemory & value); 



			virtual ~CVariant(); 



			U32 Type() const; 



			size_t Size() const; 



			void Clear(); 



			operator I08() const; 



			operator I16() const; 



			operator I32() const; 



			operator I64() const; 



			operator U08() const; 



			operator U16() const; 



			operator U32() const; 



			operator U64() const; 



			operator float() const; 



			operator double() const; 



			operator const char *() const; 



			operator const wchar_t *() const; 



			operator CMemory() const; 



			CVariant & operator=(I08 value); 



			CVariant & operator=(I16 value); 



			CVariant & operator=(I32 value); 



			CVariant & operator=(I64 value); 



			CVariant & operator=(U08 value); 



			CVariant & operator=(U16 value); 



			CVariant & operator=(U32 value); 



			CVariant & operator=(U64 value); 



			CVariant & operator=(float value); 



			CVariant & operator=(double value); 



			CVariant & operator=(const char * value); 



			CVariant & operator=(const wchar_t * value); 



			CVariant & operator=(const CMemory & value); 



			CVariant & operator=(const CVariant & value); 



			bool operator==(I08 value) const; 



			bool operator==(I16 value) const; 



			bool operator==(I32 value) const; 



			bool operator==(I64 value) const; 



			bool operator==(U08 value) const; 



			bool operator==(U16 value) const; 



			bool operator==(U32 value) const; 



			bool operator==(U64 value) const; 



			bool operator==(float value) const; 



			bool operator==(double value) const; 



			bool operator==(const char * value) const; 



			bool operator==(const wchar_t * value) const; 



			bool operator==(const CMemory & value) const; 



			bool operator==(const CVariant & value) const; 



			CVariant & operator+=(I08 value); 



			CVariant & operator+=(I16 value); 



			CVariant & operator+=(I32 value); 



			CVariant & operator+=(I64 value); 



			CVariant & operator+=(U08 value); 



			CVariant & operator+=(U16 value); 



			CVariant & operator+=(U32 value); 



			CVariant & operator+=(U64 value); 



			CVariant & operator+=(float value); 



			CVariant & operator+=(double value); 



			CVariant & operator+=(const char * value); 



			CVariant & operator+=(const wchar_t * value); 



			CVariant & operator+=(const CMemory & value); 



			CVariant & operator+=(const CVariant & value); 



			CVariant & operator-=(I08 value); 



			CVariant & operator-=(I16 value); 



			CVariant & operator-=(I32 value); 



			CVariant & operator-=(I64 value); 



			CVariant & operator-=(U08 value); 



			CVariant & operator-=(U16 value); 



			CVariant & operator-=(U32 value); 



			CVariant & operator-=(U64 value); 



			CVariant & operator-=(float value); 



			CVariant & operator-=(double value); 



			CVariant & operator-=(const char * value); 



			CVariant & operator-=(const wchar_t * value); 



			CVariant & operator-=(const CMemory & value); 



			CVariant & operator-=(const CVariant & value); 



			CVariant & operator*=(I08 value); 



			CVariant & operator*=(I16 value); 



			CVariant & operator*=(I32 value); 



			CVariant & operator*=(I64 value); 



			CVariant & operator*=(U08 value); 



			CVariant & operator*=(U16 value); 



			CVariant & operator*=(U32 value); 



			CVariant & operator*=(U64 value); 



			CVariant & operator*=(float value); 



			CVariant & operator*=(double value); 



			CVariant & operator*=(const char * value); 



			CVariant & operator*=(const wchar_t * value); 



			CVariant & operator*=(const CMemory & value); 



			CVariant & operator*=(const CVariant & value); 



			CVariant & operator/=(I08 value); 



			CVariant & operator/=(I16 value); 



			CVariant & operator/=(I32 value); 



			CVariant & operator/=(I64 value); 



			CVariant & operator/=(U08 value); 



			CVariant & operator/=(U16 value); 



			CVariant & operator/=(U32 value); 



			CVariant & operator/=(U64 value); 



			CVariant & operator/=(float value); 



			CVariant & operator/=(double value); 



			CVariant & operator/=(const char * value); 



			CVariant & operator/=(const wchar_t * value); 



			CVariant & operator/=(const CMemory & value); 



			CVariant & operator/=(const CVariant & value); 



			friend CVariant operator+(const CVariant & l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, I08 r); 



			friend CVariant operator+(I08 l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, I16 r); 



			friend CVariant operator+(I16 l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, I32 r); 



			friend CVariant operator+(I32 l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, I64 r); 



			friend CVariant operator+(I64 l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, U08 r); 



			friend CVariant operator+(U08 l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, U16 r); 



			friend CVariant operator+(U16 l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, U32 r); 



			friend CVariant operator+(U32 l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, U64 r); 



			friend CVariant operator+(U64 l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, float r); 



			friend CVariant operator+(float l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, double r); 



			friend CVariant operator+(double l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, const char * r); 



			friend CVariant operator+(const char * l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, const wchar_t * r); 



			friend CVariant operator+(const wchar_t * l, const CVariant & r); 



			friend CVariant operator+(const CVariant & l, const CMemory & r); 



			friend CVariant operator+(const CMemory & l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, I08 r); 



			friend CVariant operator-(I08 l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, I16 r); 



			friend CVariant operator-(I16 l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, I32 r); 



			friend CVariant operator-(I32 l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, I64 r); 



			friend CVariant operator-(I64 l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, U08 r); 



			friend CVariant operator-(U08 l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, U16 r); 



			friend CVariant operator-(U16 l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, U32 r); 



			friend CVariant operator-(U32 l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, U64 r); 



			friend CVariant operator-(U64 l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, float r); 



			friend CVariant operator-(float l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, double r); 



			friend CVariant operator-(double l, const CVariant & r); 


			friend CVariant operator-(const CVariant & l, const char * r); 



			friend CVariant operator-(const char * l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, const wchar_t * r); 



			friend CVariant operator-(const wchar_t * l, const CVariant & r); 



			friend CVariant operator-(const CVariant & l, const CMemory & r); 



			friend CVariant operator-(const CMemory & l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, I08 r); 



			friend CVariant operator*(I08 l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, I16 r); 



			friend CVariant operator*(I16 l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, I32 r); 



			friend CVariant operator*(I32 l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, I64 r); 



			friend CVariant operator*(I64 l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, U08 r); 



			friend CVariant operator*(U08 l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, U16 r); 



			friend CVariant operator*(U16 l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, U32 r); 



			friend CVariant operator*(U32 l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, U64 r); 



			friend CVariant operator*(U64 l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, float r); 



			friend CVariant operator*(float l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, double r); 



			friend CVariant operator*(double l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, const char * r); 



			friend CVariant operator*(const char * l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, const wchar_t * r); 



			friend CVariant operator*(const wchar_t * l, const CVariant & r); 



			friend CVariant operator*(const CVariant & l, const CMemory & r); 



			friend CVariant operator*(const CMemory & l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, I08 r); 



			friend CVariant operator/(I08 l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, I16 r); 



			friend CVariant operator/(I16 l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, I32 r); 



			friend CVariant operator/(I32 l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, I64 r); 



			friend CVariant operator/(I64 l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, U08 r); 



			friend CVariant operator/(U08 l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, U16 r); 



			friend CVariant operator/(U16 l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, U32 r); 



			friend CVariant operator/(U32 l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, U64 r); 



			friend CVariant operator/(U64 l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, float r); 



			friend CVariant operator/(float l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, double r); 



			friend CVariant operator/(double l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, const char * r); 



			friend CVariant operator/(const char * l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, const wchar_t * r); 



			friend CVariant operator/(const wchar_t * l, const CVariant & r); 



			friend CVariant operator/(const CVariant & l, const CMemory & r); 



			friend CVariant operator/(const CMemory & l, const CVariant & r); 



			bool operator<(I08 value)const ; 



			bool operator<(I16 value)const ; 



			bool operator<(I32 value)const ; 



			bool operator<(I64 value)const ; 



			bool operator<(U08 value)const ; 



			bool operator<(U16 value)const ; 



			bool operator<(U32 value)const ; 



			bool operator<(U64 value)const ; 



			bool operator<(float value)const ; 



			bool operator<(double value)const ; 



			bool operator<(const char * value)const ; 



			bool operator<(const wchar_t * value)const ; 



			bool operator<(const CMemory & value)const ; 



			bool operator<(const CVariant & value)const ; 



			bool operator<=(I08 value)const ; 



			bool operator<=(I16 value)const ; 



			bool operator<=(I32 value)const ; 



			bool operator<=(I64 value)const ; 



			bool operator<=(U08 value)const ; 



			bool operator<=(U16 value)const ; 



			bool operator<=(U32 value)const ; 



			bool operator<=(U64 value)const ; 



			bool operator<=(float value)const ; 



			bool operator<=(double value)const ; 



			bool operator<=(const char * value)const ; 



			bool operator<=(const wchar_t * value)const ; 



			bool operator<=(const CMemory & value)const ; 



			bool operator<=(const CVariant & value)const ; 



			bool operator>(I08 value)const ; 



			bool operator>(I16 value)const ; 



			bool operator>(I32 value)const ; 



			bool operator>(I64 value)const ; 



			bool operator>(U08 value)const ; 



			bool operator>(U16 value)const ; 



			bool operator>(U32 value)const ; 



			bool operator>(U64 value)const ; 



			bool operator>(float value)const ; 



			bool operator>(double value)const ; 



			bool operator>(const char * value)const ; 



			bool operator>(const wchar_t * value)const ; 



			bool operator>(const CMemory & value)const ; 



			bool operator>(const CVariant & value)const ; 



			bool operator>=(I08 value)const ; 



			bool operator>=(I16 value)const ; 



			bool operator>=(I32 value)const ; 



			bool operator>=(I64 value)const ; 



			bool operator>=(U08 value)const ; 



			bool operator>=(U16 value)const ; 



			bool operator>=(U32 value)const ; 



			bool operator>=(U64 value)const ; 



			bool operator>=(float value)const ; 



			bool operator>=(double value)const ; 



			bool operator>=(const char * value)const ; 



			bool operator>=(const wchar_t * value)const ; 



			bool operator>=(const CMemory & value)const ; 



			bool operator>=(const CVariant & value)const ; 



			bool operator!=(I08 value)const ; 



			bool operator!=(I16 value)const ; 



			bool operator!=(I32 value)const ; 



			bool operator!=(I64 value)const ; 



			bool operator!=(U08 value)const ; 



			bool operator!=(U16 value)const ; 



			bool operator!=(U32 value)const ; 



			bool operator!=(U64 value)const ; 



			bool operator!=(float value)const ; 



			bool operator!=(double value)const ; 



			bool operator!=(const char * value)const ; 



			bool operator!=(const wchar_t * value)const ; 



			bool operator!=(const CMemory & value)const ; 



			bool operator!=(const CVariant & value)const ; 



            const void * operator & ()const ;


			
			friend bool operator>(I08 l, const CVariant & r); 



			friend bool operator>(I16 l, const CVariant & r); 



			friend bool operator>(I32 l, const CVariant & r); 



			friend bool operator>(I64 l, const CVariant & r); 



			friend bool operator>(U08 l, const CVariant & r); 



			friend bool operator>(U16 l, const CVariant & r); 



			friend bool operator>(U32 l, const CVariant & r); 



			friend bool operator>(U64 l, const CVariant & r); 



			friend bool operator>(float l, const CVariant & r); 



			friend bool operator>(double l, const CVariant & r); 



			friend bool operator>(const char * l, const CVariant & r); 



			friend bool operator>(const wchar_t * l, const CVariant & r); 



			friend bool operator>(const CMemory & l, const CVariant & r); 



			friend bool operator>=(I08 l, const CVariant & r); 



			friend bool operator>=(I16 l, const CVariant & r); 



			friend bool operator>=(I32 l, const CVariant & r); 



			friend bool operator>=(I64 l, const CVariant & r); 



			friend bool operator>=(U08 l, const CVariant & r); 



			friend bool operator>=(U16 l, const CVariant & r); 



			friend bool operator>=(U32 l, const CVariant & r); 



			friend bool operator>=(U64 l, const CVariant & r); 



			friend bool operator>=(float l, const CVariant & r); 



			friend bool operator>=(double l, const CVariant & r); 



			friend bool operator>=(const char * l, const CVariant & r); 



			friend bool operator>=(const wchar_t * l, const CVariant & r); 



			friend bool operator>=(const CMemory & l, const CVariant & r); 



			friend bool operator<(I08 l, const CVariant & r); 



			friend bool operator<(I16 l, const CVariant & r); 



			friend bool operator<(I32 l, const CVariant & r); 



			friend bool operator<(I64 l, const CVariant & r); 



			friend bool operator<(U08 l, const CVariant & r); 



			friend bool operator<(U16 l, const CVariant & r); 



			friend bool operator<(U32 l, const CVariant & r); 



			friend bool operator<(U64 l, const CVariant & r); 



			friend bool operator<(float l, const CVariant & r); 



			friend bool operator<(double l, const CVariant & r); 



			friend bool operator<(const char * l, const CVariant & r); 



			friend bool operator<(const wchar_t * l, const CVariant & r); 



			friend bool operator<(const CMemory & l, const CVariant & r); 



			friend bool operator<=(I08 l, const CVariant & r); 



			friend bool operator<=(I16 l, const CVariant & r); 



			friend bool operator<=(I32 l, const CVariant & r); 



			friend bool operator<=(I64 l, const CVariant & r); 



			friend bool operator<=(U08 l, const CVariant & r); 



			friend bool operator<=(U16 l, const CVariant & r); 



			friend bool operator<=(U32 l, const CVariant & r); 



			friend bool operator<=(U64 l, const CVariant & r); 



			friend bool operator<=(float l, const CVariant & r); 



			friend bool operator<=(double l, const CVariant & r); 



			friend bool operator<=(const char * l, const CVariant & r); 



			friend bool operator<=(const wchar_t * l, const CVariant & r); 



			friend bool operator<=(const CMemory & l, const CVariant & r); 



			friend bool operator!=(I08 l, const CVariant & r); 



			friend bool operator!=(I16 l, const CVariant & r); 



			friend bool operator!=(I32 l, const CVariant & r); 



			friend bool operator!=(I64 l, const CVariant & r); 



			friend bool operator!=(U08 l, const CVariant & r); 



			friend bool operator!=(U16 l, const CVariant & r); 



			friend bool operator!=(U32 l, const CVariant & r); 



			friend bool operator!=(U64 l, const CVariant & r); 



			friend bool operator!=(float l, const CVariant & r); 



			friend bool operator!=(double l, const CVariant & r); 



			friend bool operator!=(const char * l, const CVariant & r); 



			friend bool operator!=(const wchar_t * l, const CVariant & r); 



			friend bool operator!=(const CMemory & l, const CVariant & r); 



			friend bool operator==(I08 l, const CVariant & r); 



			friend bool operator==(I16 l, const CVariant & r); 



			friend bool operator==(I32 l, const CVariant & r); 



			friend bool operator==(I64 l, const CVariant & r); 



			friend bool operator==(U08 l, const CVariant & r); 



			friend bool operator==(U16 l, const CVariant & r); 



			friend bool operator==(U32 l, const CVariant & r); 



			friend bool operator==(U64 l, const CVariant & r); 



			friend bool operator==(float l, const CVariant & r); 



			friend bool operator==(double l, const CVariant & r); 



			friend bool operator==(const char * l, const CVariant & r); 



			friend bool operator==(const wchar_t * l, const CVariant & r); 



			friend bool operator==(const CMemory & l, const CVariant & r); 



            template<class A>
            void Serialize(A & ar, bool is_save)
            {
                UNREFERENCED_PARAMETER( is_save );
                ar.Bind( variant );
            }

	};  //end class CVariant



} //end namespace atom



#endif
