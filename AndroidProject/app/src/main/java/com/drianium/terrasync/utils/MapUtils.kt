package com.drianium.terrasync.helpers

import android.view.MotionEvent
import android.view.View

fun isTouchOutsideView(view: View, event: MotionEvent): Boolean {
    if (view.visibility != View.VISIBLE) return true
    val location = IntArray(2)
    view.getLocationOnScreen(location)
    val x = event.rawX.toInt()
    val y = event.rawY.toInt()
    return !(x >= location[0] && x <= location[0] + view.width &&
            y >= location[1] && y <= location[1] + view.height)
}

