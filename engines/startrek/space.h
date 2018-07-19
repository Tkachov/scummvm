/* ScummVM - Graphic Adventure Engine
 *
 * ScummVM is the legal property of its developers, whose names
 * are too numerous to list here. Please refer to the COPYRIGHT
 * file distributed with this source distribution.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 */

#ifndef STARTREK_SPACE_H
#define STARTREK_SPACE_H

#include "fixedint.h"

namespace StarTrek {

class FileStream;

template<typename T>
struct TPoint {
	T x;
	T y;
	T z;

	TPoint() : x(0), y(0), z(0) {}
	TPoint(T _x, T _y, T _z) : x(_x), y(_y), z(_z) {}

	TPoint<T> operator+(const TPoint<T> &p) const {
		TPoint<T> p2;
		p2.x = x + p.x;
		p2.y = y + p.y;
		p2.z = z + p.z;
		return p2;
	}
	TPoint<T> operator-(const TPoint<T> &p) const {
		TPoint<T> p2;
		p2.x = x - p.x;
		p2.y = y - p.y;
		p2.z = z - p.z;
		return p2;
	}
	T &operator[](int i) {
		if (i == 0)
			return x;
		else if (i == 1)
			return y;
		else if (i == 2)
			return z;
		assert(false);
	}
	T operator[](int i) const {
		if (i == 0)
			return x;
		else if (i == 1)
			return y;
		else if (i == 2)
			return z;
		assert(false);
	}
};

typedef TPoint<int32> Point3;
typedef TPoint<Fixed14> Point3W;


template<typename T>
struct TMatrix {
private:
	T m[3];

public:
	TMatrix() {}
	TMatrix(const TMatrix<T> &mat) {
		m[0] = mat.m[0];
		m[1] = mat.m[1];
		m[2] = mat.m[2];
	}
	T &operator[](int i) {
		return m[i];
	};
	T operator[](int i) const {
		return m[i];
	};

	TMatrix<T> invert() {
		TMatrix<T> ret;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				ret[i][j] = m[j][i];
			}
		}
		return ret;
	}
};

typedef TMatrix<Point3W> Matrix;

struct Star {
	bool active;
	Point3 pos;
};

// Struct for objects in space.
// TODO: what does this stand for? Maybe rename it.
struct R3 {
	Point3 pos; // 0x0
	int16 field1e; // 0x1e
	int16 field20; // 0x20
	int16 field22; // 0x22
	int16 field24; // 0x24
	SharedPtr<FileStream> shpFile; // 0x68
};

// Maximum number of stars visible at once in the starfields
#define NUM_STARS 16

// Maximum number of R3 objects in space at once
#define NUM_SPACE_OBJECTS 0x30

}

#endif