package im.actor.model.api.rpc;
/*
 *  Generated by the Actor API Scheme generator.  DO NOT EDIT!
 */

import im.actor.model.droidkit.bser.Bser;
import im.actor.model.droidkit.bser.BserParser;
import im.actor.model.droidkit.bser.BserObject;
import im.actor.model.droidkit.bser.BserValues;
import im.actor.model.droidkit.bser.BserWriter;
import im.actor.model.droidkit.bser.DataInput;
import im.actor.model.droidkit.bser.DataOutput;
import static im.actor.model.droidkit.bser.Utils.*;
import java.io.IOException;
import im.actor.model.network.parser.*;
import java.util.List;
import java.util.ArrayList;
import im.actor.model.api.*;

public class RequestCommitFileUpload extends Request<ResponseCommitFileUpload> {

    public static final int HEADER = 0x7a;
    public static RequestCommitFileUpload fromBytes(byte[] data) throws IOException {
        return Bser.parse(new RequestCommitFileUpload(), data);
    }

    private byte[] uploadKey;
    private String fileName;

    public RequestCommitFileUpload(byte[] uploadKey, String fileName) {
        this.uploadKey = uploadKey;
        this.fileName = fileName;
    }

    public RequestCommitFileUpload() {

    }

    public byte[] getUploadKey() {
        return this.uploadKey;
    }

    public String getFileName() {
        return this.fileName;
    }

    @Override
    public void parse(BserValues values) throws IOException {
        this.uploadKey = values.getBytes(1);
        this.fileName = values.getString(2);
    }

    @Override
    public void serialize(BserWriter writer) throws IOException {
        if (this.uploadKey == null) {
            throw new IOException();
        }
        writer.writeBytes(1, this.uploadKey);
        if (this.fileName == null) {
            throw new IOException();
        }
        writer.writeString(2, this.fileName);
    }

    @Override
    public String toString() {
        String res = "rpc CommitFileUpload{";
        res += "}";
        return res;
    }

    @Override
    public int getHeaderKey() {
        return HEADER;
    }
}
