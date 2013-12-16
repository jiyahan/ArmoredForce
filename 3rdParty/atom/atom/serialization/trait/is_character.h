#ifndef IS_CHARACTER_H
#define IS_CHARACTER_H
//Begin section for file is_character.h
//TODO: Add definitions that you want preserved
//End section for file is_character.h



namespace atom
{
    //@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_L3hOAP8hEd2RG7DUnbJayA"
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<typename T>
    struct is_character
    {

        //Begin section for si::is_character
        //TODO: Add attributes that you want preserved
        //End section for si::is_character
        static const bool value = false;

    };  //end struct is_character

    //@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_L3hOAP8hEd2RG7DUnbJayA"
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<>
    struct is_character<char>
    {

        //Begin section for si::is_character
        //TODO: Add attributes that you want preserved
        //End section for si::is_character
        static const bool value = true;

    };  //end struct is_character

    //@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_L3hOAP8hEd2RG7DUnbJayA"
    //@generated "UML to C++ (com.ibm.xtools.transform.uml2.cpp.CPPTransformation)"
    template<>
    struct is_character<wchar_t>
    {

        //Begin section for si::is_character
        //TODO: Add attributes that you want preserved
        //End section for si::is_character
        static const bool value = true;

    };  //end struct is_character

} //end namespace atom

#endif
