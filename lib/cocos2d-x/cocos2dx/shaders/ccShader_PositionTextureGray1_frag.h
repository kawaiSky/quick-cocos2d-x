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

"varying vec4 fragmentColor; \n\
\n\
uniform sampler2D CC_Texture0;  \n\
varying vec2 v_texCoord;    \n\
    \n\
void main() \n\
{   \n\
    float radius = 0.01;    \n\
    vec4 accum = vec4(0.0); \n\
    vec4 normal = vec4(0.0);    \n\
    \n\
    normal = texture2D(CC_Texture0, vec2(v_texCoord.x, v_texCoord.y));  \n\
    \n\
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x - radius, v_texCoord.y-radius));  \n\
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x + radius, v_texCoord.y-radius));  \n\
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x + radius, v_texCoord.y+radius));  \n\
    accum += texture2D(CC_Texture0, vec2(v_texCoord.x - radius, v_texCoord.y+radius));  \n\
    \n\
    accum *= 1.75;  \n\
    \n\
    accum.r = 1.0;  \n\
    accum.g = 0.2;  \n\
    accum.b = 0.5;  \n\
    \n\
    normal = (accum * (1.0 - normal.a)) + (normal * normal.a);  \n\
    \n\
    gl_FragColor = fragmentColor * normal;  \n\
}   \n\
"
;