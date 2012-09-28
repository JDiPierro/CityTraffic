project(CityTraffic)

cmake_minimum_required(VERSION 2.8)

find_package(SDL REQUIRED)
find_package(SDL_image REQUIRED)

link_libraries(	${SDL_LIBRARY}
		${SDLIMAGE_LIBRARY}
		${SDLTTF_LIBRARY}
		SDLmain)

set(SOURCES
	./app/Event.cpp
	./app/App.cpp
	./app/App_OnInit.cpp
	./app/App_OnRender.cpp
	./app/App_OnUpdate.cpp
	
	./world/City.cpp
	./world/Tile.cpp
	./world/RoadSegment.cpp
)

add_executable(CityTraffic ${SOURCES})