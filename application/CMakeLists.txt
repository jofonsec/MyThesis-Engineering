#1)Primero se incluyen los codigos

	#Incluye el directorio con tus propios codigos
	INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/src)

	#Incluye completamente la libreria ParadisEO
	INCLUDE_DIRECTORIES(${PARADISEO_INCLUDE_DIR})			
				    
#2)Define los ejecutables y dependencias
	
	ADD_EXECUTABLE(generadorES GeneradorES.cpp)
	ADD_EXECUTABLE(graficarError Error.cpp)
	ADD_EXECUTABLE(AGS AGS.cpp)
	ADD_EXECUTABLE(AGMEsmp AGMEsmp.cpp)
	ADD_EXECUTABLE(AGisland-4islas AGisland.cpp)
	ADD_EXECUTABLE(AGisland-2islas AGisland-2islas.cpp)
	ADD_DEPENDENCIES(generadorES lDiscovery)
	ADD_DEPENDENCIES(graficarError lDiscovery)
	ADD_DEPENDENCIES(AGS lDiscovery)	
	ADD_DEPENDENCIES(AGMEsmp lDiscovery)
	ADD_DEPENDENCIES(AGisland-4islas lDiscovery)
	ADD_DEPENDENCIES(AGisland-2islas lDiscovery)

#3)Vincular las librerias para el ejecutable

	TARGET_LINK_LIBRARIES(generadorES ${PARADISEO_LIBRARIES} lDiscovery)
	TARGET_LINK_LIBRARIES(graficarError ${PARADISEO_LIBRARIES} lDiscovery)
	TARGET_LINK_LIBRARIES(AGS ${PARADISEO_LIBRARIES} lDiscovery)
	TARGET_LINK_LIBRARIES(AGMEsmp ${PARADISEO_LIBRARIES} lDiscovery)
	TARGET_LINK_LIBRARIES(AGisland-4islas ${PARADISEO_LIBRARIES} lDiscovery)
	TARGET_LINK_LIBRARIES(AGisland-2islas ${PARADISEO_LIBRARIES} lDiscovery)
