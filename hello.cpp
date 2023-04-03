#include <lua.hpp>
#include <iostream>

int main(int argc, char** argv)
{
    lua_State* L = luaL_newstate();
    luaL_openlibs(L);

    luaL_dofile(L, "hello.lua");

    lua_getglobal(L, "say_hello"); 
    lua_pushstring(L, "Kaushik");     
    lua_pcall(L, 1, 0, 0);
    
    lua_getglobal(L, "printInt");  
    int num = 101;
    lua_pushnumber(L, num);          
    lua_pcall(L, 1, 0, 0);
    
    lua_getglobal(L, "ValChange");  
    int num2 = 20;
    lua_pushnumber(L, num2);          
    lua_pcall(L, 1, 1, 0);
    
    int output = lua_tonumber(L,-1);
    std::cout<<"Lua Output = "<<output;
    lua_close(L);
     
    return 0;
}

