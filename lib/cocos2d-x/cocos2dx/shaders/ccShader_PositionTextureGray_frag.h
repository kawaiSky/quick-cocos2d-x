/*
 * cocos2d for iPhone: http://www.cocos2d-iphone.org
 *
 * Copyright (c) 2013 qeeplay.com
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

"                                           \n\
#ifdef GL_ES                                \n\
precision mediump float;                    \n\
#endif                                      \n\
\n\
uniform sampler2D CC_Texture0 ;                \n\
varying vec2 v_texCoord;                    \n\
varying vec4 v_fragmentColor;               \n\
\n\
void main(void)                             \n\
{                                           \n\
// Convert to greyscale using NTSC weightings               \n\
//vec4 col = texture2D(u_texture, v_texCoord);                \n\
//float grey = dot(col.rgb, vec3(0.299, 0.587, 0.114));       \n\
////float grey = getColor(col.r,col.g,col.b,col.a);       \n\
//gl_FragColor = vec4(grey, grey, grey, col.a);               \n\
float radius = 0.001;\n\
 vec3 u_outlineColor = vec3(0.0,0.0,1.0);\n\
    vec4 accum = vec4(0.0);\n\
    vec4 normal = vec4(0.0);\n\
\n\
    normal = texture2D(CC_Texture0, vec2(v_texCoord.x, v_texCoord.y));\n\
\n\
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x - radius, v_texCoord.y - radius));\n\
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x + radius, v_texCoord.y - radius));\n\
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x + radius, v_texCoord.y + radius));\n\
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x - radius, v_texCoord.y + radius));\n\
\n\
    accum *= 1.7;\n\
\n\
   accum.r = u_outlineColor.x;\n\
   accum.g = u_outlineColor.y;\n\
    accum.b = u_outlineColor.z;\n\
\n\
    normal = (accum * (1.0 - normal.a)) + (normal * normal.a);\n\
\n\
    gl_FragColor = v_fragmentColor * normal;\n\
}\n\
";
