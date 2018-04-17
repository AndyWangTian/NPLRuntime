#pragma once
#include <unordered_map>
#include "GLType.h"

#define DIRECT_COMMIT false

namespace ParaEngine
{

	/**
	* @addtogroup shaders
	* @{
	*/

	struct _hashUniformEntry;
	class GLProgram;

	typedef void(*GLInfoFunction)(GLuint program, GLenum pname, GLint* params);
	typedef void(*GLLogFunction) (GLuint program, GLsizei bufsize, GLsizei* length, GLchar* infolog);


	struct VertexAttrib
	{
		GLuint index;
		GLint size;
		GLenum type;
		std::string name;
	};

	struct Uniform
	{
		GLint location;
		GLint size;
		GLenum type;
		std::string name;
	};

	/** GLProgram
	Class that implements a glProgram


	@since v2.0.0
	*/
	class GLProgram : public CRefCountedOne
	{
		friend class GLProgramState;

	public:
		enum
		{
			VERTEX_ATTRIB_POSITION,
			VERTEX_ATTRIB_COLOR,
			VERTEX_ATTRIB_TEX_COORD,
			VERTEX_ATTRIB_NORMAL,
			VERTEX_ATTRIB_BLEND_WEIGHT,
			VERTEX_ATTRIB_BLEND_INDEX,

			VERTEX_ATTRIB_MAX,

			// backward compatibility
			VERTEX_ATTRIB_TEX_COORDS = VERTEX_ATTRIB_TEX_COORD,
		};

		enum
		{
			UNIFORM_P_MATRIX,
			UNIFORM_MV_MATRIX,
			UNIFORM_MVP_MATRIX,
			UNIFORM_TIME,
			UNIFORM_SIN_TIME,
			UNIFORM_COS_TIME,
			UNIFORM_RANDOM01,
			UNIFORM_SAMPLER0,
			UNIFORM_SAMPLER1,
			UNIFORM_SAMPLER2,
			UNIFORM_SAMPLER3,

			UNIFORM_MAX,
		};

		static const char* SHADER_NAME_POSITION_TEXTURE_COLOR;
		static const char* SHADER_NAME_POSITION_TEXTURE_COLOR_NO_MVP;
		static const char* SHADER_NAME_POSITION_TEXTURE_ALPHA_TEST;
		static const char* SHADER_NAME_POSITION_TEXTURE_ALPHA_TEST_NO_MV;
		static const char* SHADER_NAME_POSITION_COLOR;
		static const char* SHADER_NAME_POSITION_COLOR_NO_MVP;
		static const char* SHADER_NAME_POSITION_TEXTURE;
		static const char* SHADER_NAME_POSITION_TEXTURE_U_COLOR;
		static const char* SHADER_NAME_POSITION_TEXTURE_A8_COLOR;
		static const char* SHADER_NAME_POSITION_U_COLOR;
		static const char* SHADER_NAME_POSITION_LENGTH_TEXTURE_COLOR;

		static const char* SHADER_NAME_LABEL_NORMAL;
		static const char* SHADER_NAME_LABEL_OUTLINE;

		static const char* SHADER_NAME_LABEL_DISTANCEFIELD_NORMAL;
		static const char* SHADER_NAME_LABEL_DISTANCEFIELD_GLOW;

		//3D
		static const char* SHADER_3D_POSITION;
		static const char* SHADER_3D_POSITION_TEXTURE;
		static const char* SHADER_3D_SKINPOSITION_TEXTURE;

		// Attribute names
		static const char* ATTRIBUTE_NAME_COLOR;
		static const char* ATTRIBUTE_NAME_POSITION;
		static const char* ATTRIBUTE_NAME_TEX_COORD;
		static const char* ATTRIBUTE_NAME_NORMAL;
		static const char* ATTRIBUTE_NAME_BLEND_WEIGHT;
		static const char* ATTRIBUTE_NAME_BLEND_INDEX;

		GLProgram();
		virtual ~GLProgram();
		/** Initializes the GLProgram with a vertex and fragment with bytes array
		* @js initWithString
		* @lua initWithString
		*/



		/** Initializes the GLProgram with a vertex and fragment with bytes array
		* @js initWithString
		* @lua initWithString
		*/
		static GLProgram* createWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray);
		bool initWithByteArrays(const GLchar* vShaderByteArray, const GLchar* fShaderByteArray);

		/** Initializes the GLProgram with a vertex and fragment with contents of filenames
		* @js init
		* @lua init
		*/
		static GLProgram* createWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename);
		bool initWithFilenames(const std::string& vShaderFilename, const std::string& fShaderFilename);

		//void bindUniform(std::string uniformName, int value);
		Uniform* getUniform(const std::string& name);
		VertexAttrib* getVertexAttrib(const std::string& name);

		/**  It will add a new attribute to the shader by calling glBindAttribLocation */
		void bindAttribLocation(const std::string& attributeName, GLuint index) const;

		/** calls glGetAttribLocation */
		GLint getAttribLocation(const std::string& attributeName) const;

		/** calls glGetUniformLocation() */
		GLint getUniformLocation(const std::string& attributeName) const;

		/** links the glProgram */
		bool link();
		/** it will call glUseProgram() */
		void use();
		/** It will create 4 uniforms:
		- kUniformPMatrix
		- kUniformMVMatrix
		- kUniformMVPMatrix
		- GLProgram::UNIFORM_SAMPLER

		And it will bind "GLProgram::UNIFORM_SAMPLER" to 0

		*/
		void updateUniforms();

		/** calls retrieves the named uniform location for this shader program. */
		GLint getUniformLocationForName(const char* name) const;

		/** calls glUniform1i only if the values are different than the previous call for this same shader program.
		* @js setUniformLocationI32
		* @lua setUniformLocationI32
		*/
		void setUniformLocationWith1i(GLint location, GLint i1, bool direct = DIRECT_COMMIT);

		/** calls glUniform2i only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWith2i(GLint location, GLint i1, GLint i2, bool direct = DIRECT_COMMIT);

		/** calls glUniform3i only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWith3i(GLint location, GLint i1, GLint i2, GLint i3, bool direct = DIRECT_COMMIT);

		/** calls glUniform4i only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWith4i(GLint location, GLint i1, GLint i2, GLint i3, GLint i4, bool direct = DIRECT_COMMIT);

		/** calls glUniform2iv only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWith2iv(GLint location, GLint* ints, unsigned int numberOfArrays, bool direct = DIRECT_COMMIT);

		/** calls glUniform3iv only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWith3iv(GLint location, GLint* ints, unsigned int numberOfArrays, bool direct = DIRECT_COMMIT);

		/** calls glUniform4iv only if the values are different than the previous call for this same shader program. */

		void setUniformLocationWith4iv(GLint location, GLint* ints, unsigned int numberOfArrays, bool direct = DIRECT_COMMIT);

		/** calls glUniform1f only if the values are different than the previous call for this same shader program.
		* In js or lua,please use setUniformLocationF32
		* @js NA
		*/
		void setUniformLocationWith1f(GLint location, GLfloat f1, bool direct = DIRECT_COMMIT);

		/** calls glUniform2f only if the values are different than the previous call for this same shader program.
		* In js or lua,please use setUniformLocationF32
		* @js NA
		*/
		void setUniformLocationWith2f(GLint location, GLfloat f1, GLfloat f2, bool direct = DIRECT_COMMIT);

		/** calls glUniform3f only if the values are different than the previous call for this same shader program.
		* In js or lua,please use setUniformLocationF32
		* @js NA
		*/
		void setUniformLocationWith3f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3, bool direct = DIRECT_COMMIT);

		/** calls glUniform4f only if the values are different than the previous call for this same shader program.
		* In js or lua,please use setUniformLocationF32
		* @js NA
		*/
		void setUniformLocationWith4f(GLint location, GLfloat f1, GLfloat f2, GLfloat f3, GLfloat f4, bool direct = DIRECT_COMMIT);

		/** calls glUniform2fv only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWith2fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays, bool direct = DIRECT_COMMIT);

		/** calls glUniform3fv only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWith3fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays, bool direct = DIRECT_COMMIT);

		/** calls glUniform4fv only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWith4fv(GLint location, const GLfloat* floats, unsigned int numberOfArrays, bool direct = DIRECT_COMMIT);

		/** calls glUniformMatrix2fv only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWithMatrix2fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices, bool direct = DIRECT_COMMIT);

		/** calls glUniformMatrix3fv only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWithMatrix3fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices, bool direct = DIRECT_COMMIT);

		/** calls glUniformMatrix4fv only if the values are different than the previous call for this same shader program. */
		void setUniformLocationWithMatrix4fv(GLint location, const GLfloat* matrixArray, unsigned int numberOfMatrices, bool direct = DIRECT_COMMIT);



		// Attribute

		/** returns the vertexShader error log */
		std::string getVertexShaderLog() const;

		/** returns the fragmentShader error log */
		std::string getFragmentShaderLog() const;

		/** returns the program error log */
		std::string getProgramLog() const;

		// reload all shaders, this function is designed for android
		// when opengl context lost, so don't call it.
		void reset();

		inline const GLuint getProgram() const { return _program; }

		// DEPRECATED
		bool initWithVertexShaderByteArray(const GLchar* vertexByteArray, const GLchar* fragByteArray)
		{
			return initWithByteArrays(vertexByteArray, fragByteArray);
		}
		bool initWithVertexShaderFilename(const std::string &vertexFilename, const std::string& fragFilename)
		{
			return initWithFilenames(vertexFilename, fragFilename);
		}
		void addAttribute(const std::string &attributeName, GLuint index) const { return bindAttribLocation(attributeName, index); }


		void commit();
		bool isDirty() const { return _dirty; };
	protected:
		bool updateUniformLocation(GLint location, const GLvoid* data, unsigned int bytes, GLenum type, bool direct = false);


		void bindPredefinedVertexAttribs();
		void parseVertexAttribs();
		void parseUniforms();

		bool compileShader(GLuint * shader, GLenum type, const GLchar* source);
		std::string logForOpenGLObject(GLuint object, GLInfoFunction infoFunc, GLLogFunction logFunc) const;

		GLuint            _program;
		GLuint            _vertShader;
		GLuint            _fragShader;
		GLint             _builtInUniforms[UNIFORM_MAX];
		struct _hashUniformEntry* _hashForUniforms;
		bool              _hasShaderCompiler;
		bool			  _dirty;


		std::unordered_map<std::string, Uniform> _userUniforms;
		std::unordered_map<std::string, VertexAttrib> _vertexAttribs;
	};
}