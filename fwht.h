/*
 FWHT - Fast Walsh Hadamard Transform in C
 BSD license.
 by Sven Nilsen, 2012
 http://www.cutoutpro.com
 
 Version: 0.001 in angular degrees version notation
 http://isprogrammingeasy.blogspot.no/2012/08/angular-degrees-versioning-notation.html
 */
/*
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 1. Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 2. Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 The views and conclusions contained in the software and documentation are those
 of the authors and should not be interpreted as representing official policies,
 either expressed or implied, of the FreeBSD Project.
 */

/*
 
 Fast Walsh Hadamard Transform
 
 The input souce has to be in size 2^n.
 
 Example use: You have two similar images where the camera
 is moved or rotated slightly and you want to find the
 transformation of the camera movement. You then take
 two 4x4 pieces of each image and transform each color channel
 with FWHT and then take the differences, sum them
 and you will have a number that tells you how similar the
 two pieces are.
 
 When you apply a FWHT twice, you get the same as before,
 only multiplied with a factor of the size of the data.
 
 */

// Transforms a vector of integers.
void fwht_transform(int n, const int *src, int *dst);

// Normalizes the data with respect to the length.
// You might get rounding errors if the values are not
// divisible by n.
void fwht_normalize(int n, int *src);

// Finds the sum of differences between two sets of data.
// The resulted difference is divided by the length.
double fwht_sum_absolute_difference(int n, int *a, int *b);
