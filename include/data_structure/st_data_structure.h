/*
 *   MIT License
 *
 *   Copyright (c) 2017 Sidhin S Thomas
 *
 *   Permission is hereby granted, free of charge, to any person obtaining a copy
 *   of this software and associated documentation files (the "Software"), to deal
 *   in the Software without restriction, including without limitation the rights
 *   to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *   copies of the Software, and to permit persons to whom the Software is
 *   furnished to do so, subject to the following conditions:
 *
 *   The above copyright notice and this permission notice shall be included in all
 *   copies or substantial portions of the Software.
 *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *   IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *   AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *   OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *   SOFTWARE.
 */

#ifndef DATA_STRUCTURE_ST_DATA_STRUCTURE_H
#define DATA_STRUCTURE_ST_DATA_STRUCTURE_H

/*
 * Error codes:
 *  11 - memory allocation error
 *  10 - buffer underflow
 *  12 - invalid index
 */
#define ST_ENOMEN 12
#define ST_EBUFUNDR 10
#define ST_EINVAL 11
#define ST_ENOCTNR 6
#define ST_ECTNREND 9
#define ST_EIDXBND 3
#define ST_EUNXPLND 1

extern int st_errno;

#define ST_ERRNO_UNDEF

#endif //DATA_STRUCTURE_ST_DATA_STRUCTURE_H
