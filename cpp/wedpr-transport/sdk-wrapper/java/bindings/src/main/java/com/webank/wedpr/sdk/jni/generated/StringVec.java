/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (https://www.swig.org).
 * Version 4.2.1
 *
 * Do not make changes to this file unless you know what you are doing - modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package com.webank.wedpr.sdk.jni.generated;

public class StringVec extends java.util.AbstractList<String> implements java.util.RandomAccess {
    private transient long swigCPtr;
    protected transient boolean swigCMemOwn;

    protected StringVec(long cPtr, boolean cMemoryOwn) {
        swigCMemOwn = cMemoryOwn;
        swigCPtr = cPtr;
    }

    protected static long getCPtr(StringVec obj) {
        return (obj == null) ? 0 : obj.swigCPtr;
    }

    protected static long swigRelease(StringVec obj) {
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
                wedpr_java_transportJNI.delete_StringVec(swigCPtr);
            }
            swigCPtr = 0;
        }
    }

    public StringVec(String[] initialElements) {
        this();
        reserve(initialElements.length);

        for (String element : initialElements) {
            add(element);
        }
    }

    public StringVec(Iterable<String> initialElements) {
        this();
        for (String element : initialElements) {
            add(element);
        }
    }

    public String get(int index) {
        return doGet(index);
    }

    public String set(int index, String e) {
        return doSet(index, e);
    }

    public boolean add(String e) {
        modCount++;
        doAdd(e);
        return true;
    }

    public void add(int index, String e) {
        modCount++;
        doAdd(index, e);
    }

    public String remove(int index) {
        modCount++;
        return doRemove(index);
    }

    protected void removeRange(int fromIndex, int toIndex) {
        modCount++;
        doRemoveRange(fromIndex, toIndex);
    }

    public int size() {
        return doSize();
    }

    public int capacity() {
        return doCapacity();
    }

    public void reserve(int n) {
        doReserve(n);
    }

    public StringVec() {
        this(wedpr_java_transportJNI.new_StringVec__SWIG_0(), true);
    }

    public StringVec(StringVec other) {
        this(wedpr_java_transportJNI.new_StringVec__SWIG_1(StringVec.getCPtr(other), other), true);
    }

    public boolean isEmpty() {
        return wedpr_java_transportJNI.StringVec_isEmpty(swigCPtr, this);
    }

    public void clear() {
        wedpr_java_transportJNI.StringVec_clear(swigCPtr, this);
    }

    public StringVec(int count, String value) {
        this(wedpr_java_transportJNI.new_StringVec__SWIG_2(count, value), true);
    }

    private int doCapacity() {
        return wedpr_java_transportJNI.StringVec_doCapacity(swigCPtr, this);
    }

    private void doReserve(int n) {
        wedpr_java_transportJNI.StringVec_doReserve(swigCPtr, this, n);
    }

    private int doSize() {
        return wedpr_java_transportJNI.StringVec_doSize(swigCPtr, this);
    }

    private void doAdd(String x) {
        wedpr_java_transportJNI.StringVec_doAdd__SWIG_0(swigCPtr, this, x);
    }

    private void doAdd(int index, String x) {
        wedpr_java_transportJNI.StringVec_doAdd__SWIG_1(swigCPtr, this, index, x);
    }

    private String doRemove(int index) {
        return wedpr_java_transportJNI.StringVec_doRemove(swigCPtr, this, index);
    }

    private String doGet(int index) {
        return wedpr_java_transportJNI.StringVec_doGet(swigCPtr, this, index);
    }

    private String doSet(int index, String val) {
        return wedpr_java_transportJNI.StringVec_doSet(swigCPtr, this, index, val);
    }

    private void doRemoveRange(int fromIndex, int toIndex) {
        wedpr_java_transportJNI.StringVec_doRemoveRange(swigCPtr, this, fromIndex, toIndex);
    }
}