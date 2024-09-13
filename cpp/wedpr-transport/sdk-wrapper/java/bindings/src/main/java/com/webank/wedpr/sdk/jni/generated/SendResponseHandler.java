/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.2.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.webank.wedpr.sdk.jni.generated;

public class SendResponseHandler {
    private transient long swigCPtr;
    protected transient boolean swigCMemOwn;

    protected SendResponseHandler(long cPtr, boolean cMemoryOwn) {
        swigCMemOwn = cMemoryOwn;
        swigCPtr = cPtr;
    }

    protected static long getCPtr(SendResponseHandler obj) {
        return (obj == null) ? 0 : obj.swigCPtr;
    }

    protected static long swigRelease(SendResponseHandler obj) {
        long ptr = 0;
        if (obj != null) {
            if (!obj.swigCMemOwn)
                throw new RuntimeException("Cannot release ownership as memory is not owned");
            ptr = obj.swigCPtr;
            obj.swigCMemOwn = false;
            obj.delete();
        }
        return ptr;
    }

    @SuppressWarnings({"deprecation", "removal"})
    protected void finalize() {
        delete();
    }

    public synchronized void delete() {
        if (swigCPtr != 0) {
            if (swigCMemOwn) {
                swigCMemOwn = false;
                wedpr_java_transportJNI.delete_SendResponseHandler(swigCPtr);
            }
            swigCPtr = 0;
        }
    }

    public SendResponseHandler(
            SWIGTYPE_p_std__functionT_void_fstd__shared_ptrT_bcos__bytes_t_RRF_t responseFunc) {
        this(
                wedpr_java_transportJNI.new_SendResponseHandler(
                        SWIGTYPE_p_std__functionT_void_fstd__shared_ptrT_bcos__bytes_t_RRF_t
                                .getCPtr(responseFunc)),
                true);
    }

    public void sendResponse(SWIGTYPE_p_std__shared_ptrT_bcos__bytes_t payload) {
        wedpr_java_transportJNI.SendResponseHandler_sendResponse(
                swigCPtr, this, SWIGTYPE_p_std__shared_ptrT_bcos__bytes_t.swigRelease(payload));
    }
}