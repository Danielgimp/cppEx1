#include "doctest.h"
#include "PhoneticFinder.hpp"
using namespace phonetic;

#include <string>
using namespace std;



TEST_CASE("Test replacement of p and b") {
    string text = "xxx happy yyy";
    CHECK(find(text, "happy") == string("happy"));
    CHECK(find(text, "habby") == string("happy"));
    CHECK(find(text, "hapby") == string("happy"));
    CHECK(find(text, "habpy") == string("happy"));
    CHECK(find(text,"haPPy")==string("happy"));
    CHECK(find(text,"haBBY")==string("happy"));
    CHECK(find(text,"haPby")==string("happy"));
    CHECK(find(text,"habPy")==string("happy"));
    CHECK(find(text,"haBby")==string("happy"));
    CHECK(find(text,"haPpy")==string("happy"));

}

TEST_CASE("Test replacement of w and v")
{
    string text = "The Volvo Broke the Wall,What A Wave";
    CHECK(find(text, "Volvo") == string("Volvo"));
    CHECK(find(text, "Wolwo") == string("Volvo"));
    CHECK(find(text, "Volwo") == string("Volvo"));
    CHECK(find(text, "Wolwo") == string("Volvo"));
    CHECK(find(text,"Vall")==string("Wall"));
    CHECK(find(text,"Wall")==string("Wall"));
    CHECK(find(text,"Wolvo")==string("Volvo"));
    CHECK(find(text,"Wawe")==string("Wave"));
    CHECK(find(text,"Vave")==string("Wave"));
    CHECK(find(text,"Vawe")==string("Wave"));
    CHECK(find(text,"Wave")==string("Wave"));


}

TEST_CASE("Test replacement of g and j")
{
    string text = "The Jaguars Are Great Joined Together, Google it";
    CHECK(find(text, "Jaguars") == string("Jaguars"));
    CHECK(find(text, "Jajuars") == string("Jaguars"));
    CHECK(find(text, "Gajuars") == string("Jaguars"));
    CHECK(find(text, "Gaguars") == string("Jaguars"));
    CHECK(find(text,"Great")==string("Great"));
    CHECK(find(text,"Jreat")==string("Great"));
    CHECK(find(text,"Joined")==string("Joined"));
    CHECK(find(text,"Goined")==string("Joined"));
    CHECK(find(text,"Together")==string("Together"));
    CHECK(find(text,"Tojether")==string("Together"));
    CHECK(find(text,"Google")==string("Google"));
    CHECK(find(text,"Goojle")==string("Google"));
    CHECK(find(text,"Joogle")==string("Google"));
    CHECK(find(text,"Joojle")==string("Google"));

}

TEST_CASE("Test replacement of c,k and q")
{
    string text = "The Cake Was Quick To Make, Google it";
    CHECK(find(text, "Cake") == string("Cake"));
    CHECK(find(text, "Cace") == string("Cake"));
    CHECK(find(text, "Kace") == string("Cake"));
    CHECK(find(text, "Kake") == string("Cake"));
    CHECK(find(text, "Qaqe") == string("Cake"));
    CHECK(find(text, "Qake") == string("Cake"));
    CHECK(find(text,"Quick")==string("Quick"));
    CHECK(find(text,"Cuicc")==string("Quick"));
    CHECK(find(text,"Kuikk")==string("Quick"));
    CHECK(find(text,"Quiqq")==string("Quick"));
    CHECK(find(text,"Quikk")==string("Quick"));
    CHECK(find(text,"Kuiqq")==string("Quick"));
    CHECK(find(text,"Make")==string("Make"));
    CHECK(find(text,"Mace")==string("Make"));
    CHECK(find(text,"Maqe")==string("Make"));
    
}

TEST_CASE("Test replacement of s and z")
{
    string text = "The size is so big, make it as small as possible";
    CHECK(find(text, "size") == string("size"));
    CHECK(find(text, "sise") == string("size"));
    CHECK(find(text, "zize") == string("size"));
    CHECK(find(text, "zise") == string("size"));
    CHECK(find(text, "zmall") == string("small"));
    CHECK(find(text, "small") == string("small"));
    CHECK(find(text,"possible")==string("possible"));
    CHECK(find(text,"poszible")==string("possible"));
    CHECK(find(text,"pozsible")==string("possible"));
    CHECK(find(text,"pozzible")==string("possible"));
        
}

TEST_CASE("Test replacement of d and t")
{
    string text = "Hey Dude, The Title is right";
    CHECK(find(text, "Dude") == string("Dude"));
    CHECK(find(text, "Dute") == string("Dude"));
    CHECK(find(text, "Tude") == string("Dude"));
    CHECK(find(text, "Tute") == string("Dude"));
    CHECK(find(text, "Title") == string("Title"));
    CHECK(find(text, "Tidle") == string("Title"));
    CHECK(find(text,"Ditle")==string("Title"));
    CHECK(find(text,"Title")==string("Title"));
    CHECK(find(text,"right")==string("right"));
    CHECK(find(text,"righd")==string("right"));
        
}

TEST_CASE("Test replacement of o and u")
{
    string text = "The Ouya Console was one of the worst";
    CHECK(find(text, "Ouya") == string("Ouya"));
    CHECK(find(text, "Uuya") == string("Ouya"));
    CHECK(find(text, "Ooya") == string("Ouya"));
    CHECK(find(text, "Uoya") == string("Ouya"));
    CHECK(find(text, "Console") == string("Console"));
    CHECK(find(text, "Cunsule") == string("Console"));
    CHECK(find(text,"Consule")==string("Console"));
    CHECK(find(text,"Cunsole")==string("Console"));
    CHECK(find(text,"right")==string("one"));
    CHECK(find(text,"righd")==string("one"));
    CHECK(find(text,"right")==string("worst"));
    CHECK(find(text,"righd")==string("worst"));
        
}

TEST_CASE("Test replacement of i and y")
{
    string text = "You and I are going to yoga, it is final young boy";
    CHECK(find(text, "You") == string("You"));
    CHECK(find(text, "Yoy") == string("You"));
    CHECK(find(text, "Uou") == string("You"));
    CHECK(find(text, "Uoy") == string("You"));
    CHECK(find(text,"yoga")==string("yoga"));
    CHECK(find(text,"ioga")==string("yoga"));
    CHECK(find(text, "final") == string("final"));
    CHECK(find(text, "fynal") == string("final"));
    CHECK(find(text,"ioung")==string("young"));
    CHECK(find(text,"young")==string("young"));
    CHECK(find(text,"boi")==string("boy"));
    CHECK(find(text,"boy")==string("boy"));
          
}





TEST_CASE("Test replacement of lower-case and upper-case") {
    string text = "Happi xxx yyy";
    CHECK(find(text, "happi") == string("Happi"));
    CHECK(find(text, "Happi") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HaPpI") == string("Happi"));
    CHECK(find(text, "HaPpy") == string("Happi"));
    CHECK(find(text, "HAPPY") == string("Happi"));
    CHECK(find(text, "HAPPI") == string("Happi"));
    CHECK(find(text, "HappI") == string("Happi"));
   
}
