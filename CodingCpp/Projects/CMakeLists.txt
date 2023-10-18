project(${CMAKE_PROJECT_NAME})


file( GLOB FILES_SOURCE */*.cpp )

foreach( file ${FILES_SOURCE} )
	get_filename_component( filename ${file} NAME_WE )

	add_executable( ${filename} ${file} )

endforeach( file ${FILES_SOURCE} )

file( GLOB FILES_HEADER */*.h )

foreach( file ${FILES_HEADER} )
	get_filename_component( filename ${file} NAME_WE )

	if(TARGET ${filename})
		target_sources( ${filename} PRIVATE ${file} )
	else()
		# TODO add file to library
	endif()

endforeach( file ${FILES_HEADER} )