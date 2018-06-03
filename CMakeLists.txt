################################################################################
#
# Makefile
#
# Author: Benjamin Rauser
# Date:   18.03.2018
#
################################################################################

CMAKE_MINIMUM_REQUIRED( VERSION 2.8.11 )
PROJECT( cpp-templates )

OPTION( BUILD_PARANOID "Enable gcc warning and errors" TRUE)

################################################################################
#
# set compiler flags
#
################################################################################

#** check c++11 ****************************************************************
INCLUDE ( CheckCXXCompilerFlag )
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
IF   ( COMPILER_SUPPORTS_CXX11 )
	
	SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11" )
	
ELSE ( COMPILER_SUPPORTS_CXX11 )
	
	MESSAGE(FATAL_ERROR "No c++11 support found")
	
ENDIF( COMPILER_SUPPORTS_CXX11 )

#** set Werror *****************************************************************
IF   ( BUILD_PARANOID )
	SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror -Wall -Wextra -Wunreachable-code -Wreturn-type" )
	SET( CMAKE_C_FLAGS   "${CMAKE_C_FLAGS}   -Werror -Wall -Wextra -Wunreachable-code -Wreturn-type" )
ENDIF( BUILD_PARANOID )

################################################################################
#
# targets
#
################################################################################
ADD_SUBDIRECTORY( registry )
ADD_SUBDIRECTORY( singleton )
ADD_SUBDIRECTORY( observer )