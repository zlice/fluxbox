// CenterPlacement.cc
// Copyright (c) 2006 Fluxbox Team (fluxgen at fluxbox dot org)
//
// Permission is hereby granted, free of charge, to any person obtaining a
// copy of this software and associated documentation files (the "Software"),
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense,
// and/or sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.

#include "CenterPlacement.hh"

#include "FbTk/App.hh"
#include "Screen.hh"
#include "Window.hh"

bool CenterPlacement::placeWindow(const FluxboxWindow &win, int head,
                                      int &place_x, int &place_y) {

    int cent_x = (signed) win.screen().maxRight(head) - (signed) win.screen().maxLeft(head);
    int cent_y = (signed) win.screen().maxBottom(head) - (signed) win.screen().maxTop(head);

    // border on 1 side, dividing in half
    // with rounding, this will probably favor top left
    int win_half_w = (win.width() / 2) + win.fbWindow().borderWidth(),
        win_half_h = (win.height() / 2) + win.fbWindow().borderWidth();

    place_x = cent_x - win_half_w;
    place_y = cent_y - win_half_h;

    return true;
}
