


/*----------------------------------------------------------
// Decoder Ring for ConnOutFlowStats
// [conn][%p] OUT: BytesSent=%llu InFlight=%u InFlightMax=%u CWnd=%u SSThresh=%u ConnFC=%llu ISB=%llu PostedBytes=%llu SRtt=%u
// QuicTraceEvent(
        ConnOutFlowStats,
        "[conn][%p] OUT: BytesSent=%llu InFlight=%u InFlightMax=%u CWnd=%u SSThresh=%u ConnFC=%llu ISB=%llu PostedBytes=%llu SRtt=%u",
        Connection,
        Connection->Stats.Send.TotalBytes,
        Connection->CongestionControl.BytesInFlight,
        Connection->CongestionControl.BytesInFlightMax,
        Connection->CongestionControl.CongestionWindow,
        Connection->CongestionControl.SlowStartThreshold,
        Connection->Send.PeerMaxData - Connection->Send.OrderedStreamBytesSent,
        Connection->SendBuffer.IdealBytes,
        Connection->SendBuffer.PostedBytes,
        Path->GotFirstRttSample ? Path->SmoothedRtt : 0);
// arg2 = arg2 = Connection
// arg3 = arg3 = Connection->Stats.Send.TotalBytes
// arg4 = arg4 = Connection->CongestionControl.BytesInFlight
// arg5 = arg5 = Connection->CongestionControl.BytesInFlightMax
// arg6 = arg6 = Connection->CongestionControl.CongestionWindow
// arg7 = arg7 = Connection->CongestionControl.SlowStartThreshold
// arg8 = arg8 = Connection->Send.PeerMaxData - Connection->Send.OrderedStreamBytesSent
// arg9 = arg9 = Connection->SendBuffer.IdealBytes
// arg10 = arg10 = Connection->SendBuffer.PostedBytes
// arg11 = arg11 = Path->GotFirstRttSample ? Path->SmoothedRtt : 0
----------------------------------------------------------*/
TRACEPOINT_EVENT(CLOG_CONNECTION_H, ConnOutFlowStats,
    TP_ARGS(
        const void *, arg2,
        unsigned long long, arg3,
        unsigned int, arg4,
        unsigned int, arg5,
        unsigned int, arg6,
        unsigned int, arg7,
        unsigned long long, arg8,
        unsigned long long, arg9,
        unsigned long long, arg10,
        unsigned int, arg11), 
    TP_FIELDS(
        ctf_integer_hex(uint64_t, arg2, arg2)
        ctf_integer(uint64_t, arg3, arg3)
        ctf_integer(unsigned int, arg4, arg4)
        ctf_integer(unsigned int, arg5, arg5)
        ctf_integer(unsigned int, arg6, arg6)
        ctf_integer(unsigned int, arg7, arg7)
        ctf_integer(uint64_t, arg8, arg8)
        ctf_integer(uint64_t, arg9, arg9)
        ctf_integer(uint64_t, arg10, arg10)
        ctf_integer(unsigned int, arg11, arg11)
    )
)



/*----------------------------------------------------------
// Decoder Ring for ConnOutFlowStreamStats
// [conn][%p] OUT: StreamFC=%llu StreamSendWindow=%llu
// QuicTraceEvent(
        ConnOutFlowStreamStats,
        "[conn][%p] OUT: StreamFC=%llu StreamSendWindow=%llu",
        Connection,
        FcAvailable,
        SendWindow);
// arg2 = arg2 = Connection
// arg3 = arg3 = FcAvailable
// arg4 = arg4 = SendWindow
----------------------------------------------------------*/
TRACEPOINT_EVENT(CLOG_CONNECTION_H, ConnOutFlowStreamStats,
    TP_ARGS(
        const void *, arg2,
        unsigned long long, arg3,
        unsigned long long, arg4), 
    TP_FIELDS(
        ctf_integer_hex(uint64_t, arg2, arg2)
        ctf_integer(uint64_t, arg3, arg3)
        ctf_integer(uint64_t, arg4, arg4)
    )
)



/*----------------------------------------------------------
// Decoder Ring for ConnInFlowStats
// [conn][%p] IN: BytesRecv=%llu
// QuicTraceEvent(
        ConnInFlowStats,
        "[conn][%p] IN: BytesRecv=%llu",
        Connection,
        Connection->Stats.Recv.TotalBytes);
// arg2 = arg2 = Connection
// arg3 = arg3 = Connection->Stats.Recv.TotalBytes
----------------------------------------------------------*/
TRACEPOINT_EVENT(CLOG_CONNECTION_H, ConnInFlowStats,
    TP_ARGS(
        const void *, arg2,
        unsigned long long, arg3), 
    TP_FIELDS(
        ctf_integer_hex(uint64_t, arg2, arg2)
        ctf_integer(uint64_t, arg3, arg3)
    )
)



/*----------------------------------------------------------
// Decoder Ring for ConnStats
// [conn][%p] STATS: SRtt=%u CongestionCount=%u PersistentCongestionCount=%u SendTotalBytes=%llu RecvTotalBytes=%llu
// QuicTraceEvent(
        ConnStats,
        "[conn][%p] STATS: SRtt=%u CongestionCount=%u PersistentCongestionCount=%u SendTotalBytes=%llu RecvTotalBytes=%llu",
        Connection,
        Path->SmoothedRtt,
        Connection->Stats.Send.CongestionCount,
        Connection->Stats.Send.PersistentCongestionCount,
        Connection->Stats.Send.TotalBytes,
        Connection->Stats.Recv.TotalBytes);
// arg2 = arg2 = Connection
// arg3 = arg3 = Path->SmoothedRtt
// arg4 = arg4 = Connection->Stats.Send.CongestionCount
// arg5 = arg5 = Connection->Stats.Send.PersistentCongestionCount
// arg6 = arg6 = Connection->Stats.Send.TotalBytes
// arg7 = arg7 = Connection->Stats.Recv.TotalBytes
----------------------------------------------------------*/
TRACEPOINT_EVENT(CLOG_CONNECTION_H, ConnStats,
    TP_ARGS(
        const void *, arg2,
        unsigned int, arg3,
        unsigned int, arg4,
        unsigned int, arg5,
        unsigned long long, arg6,
        unsigned long long, arg7), 
    TP_FIELDS(
        ctf_integer_hex(uint64_t, arg2, arg2)
        ctf_integer(unsigned int, arg3, arg3)
        ctf_integer(unsigned int, arg4, arg4)
        ctf_integer(unsigned int, arg5, arg5)
        ctf_integer(uint64_t, arg6, arg6)
        ctf_integer(uint64_t, arg7, arg7)
    )
)



/*----------------------------------------------------------
// Decoder Ring for ConnPacketStats
// [conn][%p] STATS: SendTotalPackets=%llu SendSuspectedLostPackets=%llu SendSpuriousLostPackets=%llu RecvTotalPackets=%llu RecvReorderedPackets=%llu RecvDroppedPackets=%llu RecvDuplicatePackets=%llu RecvDecryptionFailures=%llu
// QuicTraceEvent(
        ConnPacketStats,
        "[conn][%p] STATS: SendTotalPackets=%llu SendSuspectedLostPackets=%llu SendSpuriousLostPackets=%llu RecvTotalPackets=%llu RecvReorderedPackets=%llu RecvDroppedPackets=%llu RecvDuplicatePackets=%llu RecvDecryptionFailures=%llu",
        Connection,
        Connection->Stats.Send.TotalPackets,
        Connection->Stats.Send.SuspectedLostPackets,
        Connection->Stats.Send.SpuriousLostPackets,
        Connection->Stats.Recv.TotalPackets,
        Connection->Stats.Recv.ReorderedPackets,
        Connection->Stats.Recv.DroppedPackets,
        Connection->Stats.Recv.DuplicatePackets,
        Connection->Stats.Recv.DecryptionFailures);
// arg2 = arg2 = Connection
// arg3 = arg3 = Connection->Stats.Send.TotalPackets
// arg4 = arg4 = Connection->Stats.Send.SuspectedLostPackets
// arg5 = arg5 = Connection->Stats.Send.SpuriousLostPackets
// arg6 = arg6 = Connection->Stats.Recv.TotalPackets
// arg7 = arg7 = Connection->Stats.Recv.ReorderedPackets
// arg8 = arg8 = Connection->Stats.Recv.DroppedPackets
// arg9 = arg9 = Connection->Stats.Recv.DuplicatePackets
// arg10 = arg10 = Connection->Stats.Recv.DecryptionFailures
----------------------------------------------------------*/
TRACEPOINT_EVENT(CLOG_CONNECTION_H, ConnPacketStats,
    TP_ARGS(
        const void *, arg2,
        unsigned long long, arg3,
        unsigned long long, arg4,
        unsigned long long, arg5,
        unsigned long long, arg6,
        unsigned long long, arg7,
        unsigned long long, arg8,
        unsigned long long, arg9,
        unsigned long long, arg10), 
    TP_FIELDS(
        ctf_integer_hex(uint64_t, arg2, arg2)
        ctf_integer(uint64_t, arg3, arg3)
        ctf_integer(uint64_t, arg4, arg4)
        ctf_integer(uint64_t, arg5, arg5)
        ctf_integer(uint64_t, arg6, arg6)
        ctf_integer(uint64_t, arg7, arg7)
        ctf_integer(uint64_t, arg8, arg8)
        ctf_integer(uint64_t, arg9, arg9)
        ctf_integer(uint64_t, arg10, arg10)
    )
)



/*----------------------------------------------------------
// Decoder Ring for ConnOutFlowBlocked
// [conn][%p] Send Blocked Flags: %hhu
// QuicTraceEvent(
            ConnOutFlowBlocked,
            "[conn][%p] Send Blocked Flags: %hhu",
            Connection,
            Connection->OutFlowBlockedReasons);
// arg2 = arg2 = Connection
// arg3 = arg3 = Connection->OutFlowBlockedReasons
----------------------------------------------------------*/
TRACEPOINT_EVENT(CLOG_CONNECTION_H, ConnOutFlowBlocked,
    TP_ARGS(
        const void *, arg2,
        unsigned char, arg3), 
    TP_FIELDS(
        ctf_integer_hex(uint64_t, arg2, arg2)
        ctf_integer(unsigned char, arg3, arg3)
    )
)



/*----------------------------------------------------------
// Decoder Ring for ConnSourceCidRemoved
// [conn][%p] (SeqNum=%llu) Removed Source CID: %!CID!
// QuicTraceEvent(
                    ConnSourceCidRemoved,
                    "[conn][%p] (SeqNum=%llu) Removed Source CID: %!CID!",
                    Connection,
                    SourceCid->CID.SequenceNumber,
                    CASTED_CLOG_BYTEARRAY(SourceCid->CID.Length, SourceCid->CID.Data));
// arg2 = arg2 = Connection
// arg3 = arg3 = SourceCid->CID.SequenceNumber
// arg4 = arg4 = CASTED_CLOG_BYTEARRAY(SourceCid->CID.Length, SourceCid->CID.Data)
----------------------------------------------------------*/
TRACEPOINT_EVENT(CLOG_CONNECTION_H, ConnSourceCidRemoved,
    TP_ARGS(
        const void *, arg2,
        unsigned long long, arg3,
        unsigned int, arg4_len,
        const void *, arg4), 
    TP_FIELDS(
        ctf_integer_hex(uint64_t, arg2, arg2)
        ctf_integer(uint64_t, arg3, arg3)
        ctf_integer(unsigned int, arg4_len, arg4_len)
        ctf_sequence(char, arg4, arg4, unsigned int, arg4_len)
    )
)
