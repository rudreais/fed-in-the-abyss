workspace "roguelike"
    configurations { "Release", "Debug" }
        location "build/"

project "roguelike"

    kind "ConsoleApp"
    files {
        "**.h",
        "**.c"
        }

    links { "ncurses" }

    includedirs { "include/" }

    configuration { "linux", "gmake" }
        buildoptions { "-W", "-Wall", "-Wextra", "-g3" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"
        targetsuffix "-d"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

    filter "platforms:x86"
        architecture "x86"

    filter "platforms:x64"
        architecture "x86_64"