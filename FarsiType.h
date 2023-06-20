#pragma once


enum FarsiArabicTashkeel_
{
    fat_FATHEH,
    fat_TANVIN_NASB,
    fat_ZAMMEH,
    fat_TANVIN_RAF,
    fat_KASREH,
    fat_TANVIN_JARR,
    fat_SOKOON,
    fat_TASHDID,
    fat_Tashkeel_Count
};

enum FarsiArabicTashkeel_ArabicNames_
{
    fat_FATHA = fat_FATHEH,
    fat_FATHA_TAN = fat_TANVIN_NASB,
    fat_DAMMA = fat_ZAMMEH,
    fat_DAMMA_TAN = fat_TANVIN_RAF,
    fat_KASRA = fat_KASREH,
    fat_KASRA_TAN = fat_TANVIN_JARR,
    fat_SUKUN = fat_SOKOON,
    fat_SHADDA = fat_TASHDID
};

enum FarsiArabicAlphabets_
{
    faa_ALEF_HAMZEH_ABOVE, 
    faa_ALEF, 
    faa_ALEF_MAD_ABOVE, 
    faa_HAMZEH, 
    faa_VAAV_HAMZEH_ABOVE, 
    faa_ALEF_HAMZEH_BELOW, 
    faa_YEH_HAMZEH_ABOVE,
    faa_BEH, 
    faa_PEH, 
    faa_TEH, 
    faa_TEH_TANIS, 
    faa_SEH, 
    faa_JEEM, 
    faa_CHEH, 
    faa_HEH_JEEMY, 
    faa_KHEH, 
    faa_DAAL, 
    faa_ZAAL, 
    faa_REH, 
    faa_ZEH, 
    faa_JEH, 
    faa_SEEN, 
    faa_SHEEN, 
    faa_SAAD, 
    faa_ZAAD, 
    faa_TAAH, 
    faa_ZAAH, 
    faa_AIN, 
    faa_GHAIN,
    faa_FEH, 
    faa_QAAF, 
    faa_KAAF, 
    faa_KAAF_NO_HEAD, 
    faa_GAAF, 
    faa_LAAM, 
    faa_MEEM, 
    faa_NOON, 
    faa_VAAV, 
    faa_HEH, 
    faa_YEH, 
    faa_ARABIC_YEH, 
    faa_ALEF_MAKSURA, 
    faa_TATWEEL, 
    faa_LAAM_ALEF, 
    faa_LAAM_ALEF_HAMZA_ABOVE, 
};

enum FarsiArabicAlphabets_ArabicNames_
{
    faa_ALEF_HAMZA_ABOVE = faa_ALEF_HAMZEH_ABOVE,
    faa_ALEF_MADDA_ABOVE = faa_ALEF_MAD_ABOVE,
    faa_HAMZA = faa_HAMZEH,
    faa_WAAW_HAMZA_ABOVE = faa_VAAV_HAMZEH_ABOVE,
    faa_ALEF_HAMZA_BELOW = faa_ALEF_HAMZEH_BELOW,
    faa_YEH_HAMZA_ABOVE = faa_YEH_HAMZEH_ABOVE,
    faa_TEH_MARBUTA = faa_TEH_TANIS,
    faa_THEH = faa_SEH,
    faa_HAH = faa_HEH_JEEMY,
    faa_THAAL = faa_ZAAL,
    faa_ZAIN = faa_ZEH,
    faa_DAAD = faa_ZAAD,
    faa_KAAF_ARABIC = faa_KAAF_NO_HEAD,
    faa_KEHEH = faa_KAAF,
    faa_WAAW = faa_VAAV
};

enum FarsiArabicAlphabets_Forms_
{
    faa_Unicode,
    faa_Isolated,
    faa_Beginner,
    faa_Medium,
    faa_Final,
};

extern const std::vector<std::vector<std::string>> fa_AlphabetsAllForms;

namespace FarsiType
{
    /// <summary>Get Farsi/Arabic character place in a word for its form, depending its previous and next character.</summary>
    /// <param name="fa_character">Character you want to check its place.</param>
    /// <param name="prevFAChar">Previous character, to check if its connected to fa_character or not.</param>
    /// <param name="nextFAChar">Next character, to check if its connected to fa_character or not.</param>
    /// <returns>Returns an int in type of a char. Possible values: 0- no connection, 1- conntected from behind, 2- connected from front, 3- connected from both side.</returns>
    unsigned char GetFACharPlace(const std::string &fa_character, const std::string &prevFAChar, const std::string &nextFAChar);

    /// <summary>Check if given character is a Farsi/Arabic letter in beginner form or not.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsFACharBeginner(const std::string &fa_character);

    /// <summary>Find vector index of the give character in fa_AlphabetsAllForms vector</summary>
    /// <param name="fa_character">Character you want get its index.</param>
    /// <returns>Returns an int in type of a char. Possible values: 0 to 44 (fa_AlphabetsAllForms array size).</returns>
    unsigned char FindFACharIndex(const std::string &fa_character);

    /// <summary>Check if given character is a Farsi/Arabic letter or not.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <returns>Returns a bool value. Possible values: true, false.</returns>
    bool IsFAChar(const std::string &fa_character);

    /// <summary>Reverses Farsi/Arabic string and returns a vector of std::strings, each of them containing Farsi/Arabic letters with different byte counts.</summary>
    /// <param name="str">Farsi/Arabic string.</param>
    /// <returns>Returns a vector of std::strings.</returns>
    std::vector<std::string> ReverseFAText(const std::string &str);

    /// <summary>Get correct unicode of Farsi/Arabic letter depending on its position, previous, and next letters.</summary>
    /// <param name="fa_character">Character you want to check.</param>
    /// <param name="prevFAChar">Previous character, to check if its connected to fa_character or not.</param>
    /// <param name="nextFAChar">Next character, to check if its connected to fa_character or not.</param>
    /// <returns>Returns a std::string.</returns>
    std::string GetFACharGlyph(const std::string &fa_character, const std::string &prevFAChar, const std::string &nextFAChar);

    /// <summary>Converts a Farsi/Arabic string to a normal, fixed, not-reversed string for using it in you program :).</summary>
    /// <param name="text">Farsi/Arabic text.</param>
    /// <returns>Returns a std::string. Fixed Farsi/Arabic string</returns>
    std::string ConvertToFAGlyphs(const std::string &text);
};
