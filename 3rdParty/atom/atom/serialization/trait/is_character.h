#ifndef IS_CHARACTER_H
#define IS_CHARACTER_H



namespace atom
{
    //@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_L3hOAP8hEd2RG7DUnbJayA"
    template<typename T>
    struct is_character
    {

        static const bool value = false;

    };  //end struct is_character

    //@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_L3hOAP8hEd2RG7DUnbJayA"
    template<>
    struct is_character<char>
    {

        static const bool value = true;

    };  //end struct is_character

    //@uml.annotationsderived_abstraction="platform:/resource/SystemInterface/document/System%20Interface.emx#_L3hOAP8hEd2RG7DUnbJayA"
    template<>
    struct is_character<wchar_t>
    {

        static const bool value = true;

    };  //end struct is_character

} //end namespace atom

#endif
